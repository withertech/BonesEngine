#pragma once
#include <bnspch.h>
#include <debugbreak.h>
#define BIT(x) (1 << x)

#if defined(BNS_PLATFORM_WINDOWS)
#ifdef BNS_BUILD_DLL
#define BNS_API __declspec(dllexport)
#else
#define BNS_API __declspec(dllimport)
#endif

#elif defined(BNS_PLATFORM_LINUX)
#define BNS_API
#else
#error Unsupported Platform!
#endif

#ifdef BNS_ENABLE_ASSERTS
#define BNS_ASSERT(x, ...)                                   \
	{                                                        \
		if (!x)                                              \
		{                                                    \
			BNS_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			debug_break();                                   \
		}                                                    \
	}
#define BNS_CORE_ASSERT(x, ...)                                   \
	{                                                             \
		if (!x)                                                   \
		{                                                         \
			BNS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			debug_break();                                        \
		}                                                         \
	}
#else
#define BNS_ASSERT(x, ...)
#define BNS_CORE_ASSERT(x, ...)
#endif

#define BNS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)