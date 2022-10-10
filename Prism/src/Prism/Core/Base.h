#pragma once

#include "Prism/Core/PlatformDetection.h"

#include <memory>

#ifdef PM_DEBUG
#define PM_ENABLE_ASSERTS
#if defined(PM_PLATFORM_WINDOWS)
#define PM_DEBUGBREAK() __debugbreak()
#elif defined(PM_PLATFORM_LINUX)
#include <signal.h>
#define PM_DEBUGBREAK() raise(SIGTRAP)
#elif defined(PM_PLATFORM_MACOS)
#include <signal.h>
#define PM_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define PM_ENABLE_ASSERTS
#else
#define PM_DEBUGBREAK()
#endif

#ifdef PM_PLATFORM_WINDOWS
#define PM_API
#ifdef PM_SUPPORT_DLL
#ifdef PM_BUILD_DLL
#define PM_API __declspec(dllexport)
#else
#define PM_API __declspec(dllimport)
#endif
#endif
#else
#pragma Prism DLL only supports Windows !
#define PM_API
#endif

namespace Prism
{

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T, typename... Args>
    constexpr Scope<T> CreateScope(Args &&...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename T, typename... Args>
    constexpr Ref<T> CreateRef(Args &&...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#include "Prism/Log/Log.h"
#include "Prism/Core/Assert.h"