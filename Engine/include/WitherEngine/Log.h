#pragma once
#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace WitherEngine
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define WIT_CORE_TRACE(...) ::WitherEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WIT_CORE_INFO(...) ::WitherEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WIT_CORE_WARN(...) ::WitherEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WIT_CORE_ERROR(...) ::WitherEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WIT_CORE_CRITICAL(...) ::WitherEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define WIT_TRACE(...) ::WitherEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WIT_INFO(...) ::WitherEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define WIT_WARN(...) ::WitherEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WIT_ERROR(...) ::WitherEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define WIT_CRITICAL(...) ::WitherEngine::Log::GetClientLogger()->critical(__VA_ARGS__)