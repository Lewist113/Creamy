workspace "CreamEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- include directories relative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "CreamEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "CreamEngine/vendor/Glad/include"
IncludeDir["imgui"] = "CreamEngine/vendor/imgui"

include "CreamEngine/vendor/GLFW"
include "CreamEngine/vendor/Glad"
include "CreamEngine/vendor/imgui"


project "CreamEngine"
	location "CreamEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir.. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir.. "/%{prj.name}")

	pchheader "crpch.h"
	pchsource "CreamEngine/src/crpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"

	}

	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CR_PLATFORM_WINDOWS",
			"CR_BUILD_DLL"
		}	

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CR_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "CR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CR_DIST"
		buildoptions "/MD"
		optimize "On"
		 
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir.. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir.. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CreamEngine/vendor/spdlog/include",
		"CreamEngine/src"
	}

	links 
	{
		"CreamEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CR_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "CR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CR_DIST"
		buildoptions "/MD"
		optimize "On"
