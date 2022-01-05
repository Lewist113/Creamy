#pragma once


#ifdef CR_PLATFORM_WINDOWS
	#ifdef CR_BUILD_DLL
		#define CREAMENGINE_API __declspec(dllexport)
	#else
		#define CREAMENGINE_API __declspec(dllimport)
	#endif 
#else
	#error CreamEngine only supports windows!
#endif