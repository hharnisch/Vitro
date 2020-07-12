#pragma once

#include "_pch.h"
#include "Vitro/Diagnostics/LogLevel.h"

#include <list>
#include <mutex>

namespace Vitro
{
	class Log
	{
	public:
		struct Entry
		{
			bool FromEngine;
			LogLevel Level;
			std::string Message;
		};

		// Initializes logging functionality.
		static void Initialize(const std::string& appLogPath, const std::string& engineLogPath);

		// Don't call this! Use the macros below.
		static void Enqueue(const Entry& entry);

		template<typename M>
		std::enable_if_t<std::is_arithmetic_v<M>, std::string> static Concat(const M& msg)
		{
			return std::to_string(msg);
		}

		template<typename M>
		std::enable_if_t<!std::is_arithmetic_v<M>, std::string> static Concat(const M& msg)
		{
			return static_cast<std::string>(msg);
		}

		template<typename M, typename... Args>
		static std::string Concat(const M& msg, const Args&... args)
		{
			return Concat(msg) + " | " + Concat(args...);
		}

	private:
		static bool Initialized;
		static std::ostream* AppLogTarget;
		static std::ostream* EngineLogTarget;
		static std::list<Entry> Queue;
		static std::mutex Mutex;

		static void StartQueueProcessing();
		static void Dequeue();
		static void SetConsoleColors(uint8_t colorMask);

		Log() = delete;
	};
}

#define $Log ::Vitro::Log
#define LogTrace(...) $Log::Enqueue({false, ::Vitro::LogLevel::Trace, $Log::Concat(__VA_ARGS__)})
#define LogDebug(...) $Log::Enqueue({false, ::Vitro::LogLevel::Debug, $Log::Concat(__VA_ARGS__)})
#define LogInfo(...) $Log::Enqueue({false, ::Vitro::LogLevel::Info, $Log::Concat(__VA_ARGS__)})
#define LogWarn(...) $Log::Enqueue({false, ::Vitro::LogLevel::Warn, $Log::Concat(__VA_ARGS__)})
#define LogError(...) $Log::Enqueue({false, ::Vitro::LogLevel::Error, $Log::Concat(__VA_ARGS__)})
#define LogFatal(...) $Log::Enqueue({false, ::Vitro::LogLevel::Fatal, $Log::Concat(__VA_ARGS__)})

#define LogEngineTrace(...) Log::Enqueue({true, LogLevel::Trace, Log::Concat(__VA_ARGS__)})
#define LogEngineDebug(...) Log::Enqueue({true, LogLevel::Debug, Log::Concat(__VA_ARGS__)})
#define LogEngineInfo(...) Log::Enqueue({true, LogLevel::Info, Log::Concat(__VA_ARGS__)})
#define LogEngineWarn(...) Log::Enqueue({true, LogLevel::Warn, Log::Concat(__VA_ARGS__)})
#define LogEngineError(...) Log::Enqueue({true, LogLevel::Error, Log::Concat(__VA_ARGS__)})
#define LogEngineFatal(...) Log::Enqueue({true, LogLevel::Fatal, Log::Concat(__VA_ARGS__)})
