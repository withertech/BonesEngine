#pragma once
#include <BonesEngine/Core.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace BonesEngine
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
		static std::string GetName();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// Core Log Macros
#define BNS_CORE_TRACE(...) ::BonesEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BNS_CORE_INFO(...) ::BonesEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BNS_CORE_WARN(...) ::BonesEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BNS_CORE_ERROR(...) ::BonesEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BNS_CORE_CRITICAL(...) ::BonesEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define BNS_TRACE(...) ::BonesEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BNS_INFO(...) ::BonesEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BNS_WARN(...) ::BonesEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BNS_ERROR(...) ::BonesEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BNS_CRITICAL(...) ::BonesEngine::Log::GetClientLogger()->critical(__VA_ARGS__)