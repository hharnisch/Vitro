#include "_pch.h"
#include "Log.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Diagnostics/Assert.h"

#include <fstream>
#include <iostream>

namespace Vitro
{
	std::ostream* Log::AppLogTarget;
	std::ostream* Log::EngineLogTarget;
	std::list<Log::Entry> Log::Queue;
	std::mutex Log::Mutex;

	void Log::Initialize(const std::string& appLogPath, const std::string& engineLogPath)
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

		std::thread(StartQueueProcessing).detach();
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
				Dequeue();
			std::this_thread::yield();
		}
		while(Queue.size())
			Dequeue();

		if(AppLogTarget != &std::cout)
			delete AppLogTarget;
		if(EngineLogTarget != &std::cout)
			delete EngineLogTarget;
	}

	void Log::Dequeue()
	{
		Mutex.lock();
		Entry entry = Queue.front();
		Queue.pop_front();
		Mutex.unlock();

		SetConsoleColors(static_cast<uint8_t>(entry.Level));

		using namespace std::chrono;
		auto now = system_clock::now().time_since_epoch();
		auto secs = duration_cast<seconds>(now).count();
		tm calendarTime;
		localtime_s(&calendarTime, &secs);

		char timestamp[14]; // Timestamp is 14 characters long with the null character.
		strftime(timestamp, sizeof(timestamp), "[%T.", &calendarTime);

		auto msecs = duration_cast<milliseconds>(now).count() % 1000 + 1000;
		auto msecsstr = std::to_string(msecs).c_str();
		for(int i = sizeof(timestamp) - 4; i < sizeof(timestamp); i++)
			timestamp[i] = msecsstr[i - sizeof(timestamp) + 5];

		auto logTarget = entry.FromEngine ? EngineLogTarget : AppLogTarget;
		auto logOrigin = entry.FromEngine ? "ENGINE" : "APP";
		std::stringstream logText;
		logText << timestamp << "] [" << logOrigin;
		if(logTarget != &std::cout)
			logText << " " << entry.Level;
		logText << "] " << entry.Message << std::endl;
		*logTarget << logText.str();
	}

	void Log::SetConsoleColors(uint8_t colorMask)
	{
	#if $WINDOWS
		Windows::API::SetConsoleColors(colorMask);
	#else
	#error No valid build platform defined.
	#endif
	}
}
