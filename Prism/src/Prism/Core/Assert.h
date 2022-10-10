#pragma once

#include "Prism/Log/Log.h"
#include "Prism/Core/Base.h"

#ifdef PM_ENABLE_ASSERTS
#define PM_ASSERT(x, ...)                                   \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            PM_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            PM_DEBUGBREAK();                                \
        }                                                   \
    }
#define PM_CORE_ASSERT(x, ...)                                   \
    {                                                            \
        if (!(x))                                                \
        {                                                        \
            PM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            PM_DEBUGBREAK();                                     \
        }                                                        \
    }
#else
#define PM_ASSERT(x, ...)
#define PM_CORE_ASSERT(x, ...)
#endif