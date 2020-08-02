#include "_pch.h"
#include "Log.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro
{
	std::ostream* Log::AppLogTarget;
	std::ostream* Log::EngineLogTarget;
	std::list<Log::Entry> Log::Queue;
	std::mutex Log::Mutex;

	void Log::Initialize(const std::string& appLogPath, const std::string& engineLogPath,
						 std::thread& loggingThread)
	{
		static bool Initialized;
		Assert(!Initialized, "Logging has already been initialized by the engine.");

		if(appLogPath.size())
			AppLogTarget = new std::ofstream(appLogPath);
		else
			AppLogTarget = &std::cout;

		if(engineLogPath.size())
			EngineLogTarget = new std::ofstream(engineLogPath);
		else
			EngineLogTarget = &std::cout;

		loggingThread = std::thread(StartQueueProcessing);
		Initialized = true;
	}

	void Log::Enqueue(const Entry& entry)
	{
		Mutex.lock();
		Queue.emplace_back(entry);
		Mutex.unlock();
	}

	void Log::StartQueueProcessing()
	{
		while(Engine::Running())
		{
			if(Queue.size())
				DequeueAndWrite();
			std::this_thread::yield();
		}
		while(Queue.size())
			DequeueAndWrite();

		if(AppLogTarget != &std::cout)
			delete AppLogTarget;
		if(EngineLogTarget != &std::cout)
			delete EngineLogTarget;
	}

	void Log::DequeueAndWrite()
	{
		Mutex.lock();
		Entry entry = Queue.front();
		Queue.pop_front();
		Mutex.unlock();

		SetConsoleColors(static_cast<uint8_t>(entry.Level));

		auto logTarget = entry.FromEngine ? EngineLogTarget : AppLogTarget;
		auto logOrigin = entry.FromEngine ? "ENGINE" : "APP";

		std::stringstream logText;
		logText << "[" << GetLogTimestamp() << "] [" << logOrigin;
		if(logTarget != &std::cout) // Append log level if not logging to the console.
			logText << " " << FileUtils::ModifyToUpper(ToString(entry.Level));
		logText << "] " << entry.Message << std::endl;

		*logTarget << logText.str();
	}

	void Log::SetConsoleColors(uint8_t colorMask)
	{
	#if VTR_SYSTEM_WINDOWS
		Windows::API::SetConsoleColors(colorMask);
	#else
	#error Unsupported system.
	#endif
	}

	std::string Log::GetLogTimestamp()
	{
		using namespace std::chrono;
		auto now = system_clock::now().time_since_epoch(); // Get the current time.
		auto secs = duration_cast<seconds>(now).count();
		tm calendarTime;
		localtime_s(&calendarTime, &secs);

		char timestamp[13]; // Timestamp is 13 characters long with the null character.
		strftime(timestamp, sizeof(timestamp), "%T.", &calendarTime);

		auto msecs = duration_cast<milliseconds>(now).count(); // Append milliseconds to timestamp.
		auto msecsstr = std::to_string(msecs % 1000 + 1000).c_str();
		for(int i = sizeof(timestamp) - 4; i < sizeof(timestamp); i++)
			timestamp[i] = msecsstr[i - sizeof(timestamp) + 5];

		return timestamp;
	}
}
