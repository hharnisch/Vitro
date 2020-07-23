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

#if $APP_LOG_LEVEL > $LOG_LEVEL_TRACE
#define LogTrace(...)
#else
#define LogTrace(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Trace, ::Vitro::Log::Concat(__VA_ARGS__)})
#endif
#if $APP_LOG_LEVEL > $LOG_LEVEL_DEBUG
#define LogDebug(...)
#else
#define LogDebug(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Debug, ::Vitro::Log::Concat(__VA_ARGS__)})
#endif
#if $APP_LOG_LEVEL > $LOG_LEVEL_INFO
#define LogInfo(...)
#else
#define LogInfo(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Info, ::Vitro::Log::Concat(__VA_ARGS__)})
#endif
#if $APP_LOG_LEVEL > $LOG_LEVEL_WARN
#define LogWarn(...)
#else
#define LogWarn(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Warn, ::Vitro::Log::Concat(__VA_ARGS__)})
#endif
#define LogError(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Error, ::Vitro::Log::Concat(__VA_ARGS__)})
#define LogFatal(...) ::Vitro::Log::Enqueue({false, ::Vitro::LogLevel::Fatal, ::Vitro::Log::Concat(__VA_ARGS__)})

#if $ENGINE_LOG_LEVEL > $LOG_LEVEL_TRACE
#define LogEngineTrace(...)
#else
#define LogEngineTrace(...) Log::Enqueue({true, LogLevel::Trace, Log::Concat(__VA_ARGS__)})
#endif
#if $ENGINE_LOG_LEVEL > $LOG_LEVEL_DEBUG
#define LogEngineDebug(...)
#else
#define LogEngineDebug(...) Log::Enqueue({true, LogLevel::Debug, Log::Concat(__VA_ARGS__)})
#endif
#if $ENGINE_LOG_LEVEL > $LOG_LEVEL_INFO
#define LogEngineInfo(...)
#else
#define LogEngineInfo(...) Log::Enqueue({true, LogLevel::Info, Log::Concat(__VA_ARGS__)})
#endif
#if $ENGINE_LOG_LEVEL > $LOG_LEVEL_WARN
#define LogEngineWarn(...)
#else
#define LogEngineWarn(...) Log::Enqueue({true, LogLevel::Warn, Log::Concat(__VA_ARGS__)})
#endif
#define LogEngineError(...) Log::Enqueue({true, LogLevel::Error, Log::Concat(__VA_ARGS__)})
#define LogEngineFatal(...) Log::Enqueue({true, LogLevel::Fatal, Log::Concat(__VA_ARGS__)})
