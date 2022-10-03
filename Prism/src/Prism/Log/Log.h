#pragma once

#include "Prism/Core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Prism
{

    class PM_API Log
    {
    public:
        static void Init();

        static Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        static Ref<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
#define PM_CORE_TRACE(...) ::Prism::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PM_CORE_INFO(...) ::Prism::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PM_CORE_WARN(...) ::Prism::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PM_CORE_ERROR(...) ::Prism::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PM_CORE_CRITICAL(...) ::Prism::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PM_TRACE(...) ::Prism::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PM_INFO(...) ::Prism::Log::GetClientLogger()->info(__VA_ARGS__)
#define PM_WARN(...) ::Prism::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PM_ERROR(...) ::Prism::Log::GetClientLogger()->error(__VA_ARGS__)
#define PM_CRITICAL(...) ::Prism::Log::GetClientLogger()->critical(__VA_ARGS__)