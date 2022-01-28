#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace CreamEngine {

	class CREAMENGINE_API Log
	{
	public:

		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core Log MACROS

#define CR_CORE_TRACE(...)     ::CreamEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...)      ::CreamEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...)      ::CreamEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...)     ::CreamEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_FATAL(...)     ::CreamEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log MACROS
#define CR_TRACE(...)   ::CreamEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...)    ::CreamEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...)    ::CreamEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...)   ::CreamEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_FATAL(...)   ::CreamEngine::Log::GetClientLogger()->critical(__VA_ARGS__)


