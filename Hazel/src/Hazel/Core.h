#pragma once

#include "optick.h"

#define HZ_PLATFORM_WINDOWS
#define HZ_ENABLE_ASSERTS


#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

// EVENT STUFF
#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// OPTICK STUFF
#define HZ_OPTICK false
#define HZ_OPTICK_INIT() if(HZ_OPTICK) { OPTICK_FRAME("MainThread"); }
#define HZ_PROFILE() if(HZ_OPTICK) { OPTICK_EVENT(); }

// RENDERER STUFF

#define HZ_DEFAULT_SHADERS "1393949"

#define HZ_DEFAULT_VERTEX_SHADER "#version 330 core\nlayout(location = 0) in vec3 vertexPosition_modelspace;\nvoid main(){\ngl_Position.xyz = vertexPosition_modelspace;\ngl_Position.w = 1.0;\n}"
								
#define HZ_DEFAULT_FRAGMENT_SHADER "#version 330 core\nout vec3 color;\nvoid main(){\ncolor = vec3(1,0,0);\n}"