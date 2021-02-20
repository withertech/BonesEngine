#pragma once
#include <witpch.h>
#define BIT(x) (1 << x)
#if !defined(_MSC_VER) && !defined(WIN32)
#include <signal.h>
#define __debugbreak()  \
	{                   \
		raise(SIGTRAP); \
	}
#endif

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
			__debugbreak();                                  \
		}                                                    \
	}
#define WIT_CORE_ASSERT(x, ...)                                   \
	{                                                             \
		if (!x)                                                   \
		{                                                         \
			WIT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak();                                       \
		}                                                         \
	}
#else
#define WIT_ASSERT(x, ...)
#define WIT_CORE_ASSERT(x, ...)
#endif