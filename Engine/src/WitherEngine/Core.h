#pragma once
#include <witpch.h>
#include <debugbreak.h>
#define BIT(x) (1 << x)

#if defined(WIT_PLATFORM_WINDOWS)
#ifdef WIT_BUILD_DLL
#define WIT_API __declspec(dllexport)
#else
#define WIT_API __declspec(dllimport)
#endif

#elif defined(WIT_PLATFORM_LINUX)
#define WIT_API
#else
#error Unsupported Platform!
#endif

#ifdef WIT_ENABLE_ASSERTS
#define WIT_ASSERT(x, ...)                                   \
	{                                                        \
		if (!x)                                              \
		{                                                    \
			WIT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			debug_break();                                   \
		}                                                    \
	}
#define WIT_CORE_ASSERT(x, ...)                                   \
	{                                                             \
		if (!x)                                                   \
		{                                                         \
			WIT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			debug_break();                                        \
		}                                                         \
	}
#else
#define WIT_ASSERT(x, ...)
#define WIT_CORE_ASSERT(x, ...)
#endif

#define WIT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)