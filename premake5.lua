workspace "Vitro"
	architecture		"x86_64"
	configurations		{ "Debug", "Release" }
	flags				{ "MultiProcessorCompile" }
	buildoptions		{ "/D_ITERATOR_DEBUG_LEVEL=0" }
	startproject		"VitroTests"

outputdir = "%{cfg.buildcfg}_%{cfg.architecture}_%{cfg.system}"

group "Dependencies"
	include "Vitro/lib/glad"
	include "Vitro/lib/imgui"
group ""

project "Vitro"
	location			"Vitro"
	kind				"StaticLib"
	language			"C++"
	cppdialect			"C++17"
	staticruntime		"on"
	targetdir			(".bin/" .. outputdir .. "/%{prj.name}")
	objdir				(".bin_obj/" .. outputdir .. "/%{prj.name}")
	pchsource			"%{prj.name}/src/_pch.cpp"
	pchheader			"_pch.h"
	defines				"$OPENGL;$MULTIWINDOW;GLM_FORCE_SSE2;GLM_FORCE_AVX"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/lib"
	}
	
	libdirs
	{
		"%{prj.name}/lib"
	}
	
	links
	{
		"opengl32.lib",
		"glad",
		"imgui"
	}

	filter "system:windows"
		systemversion	"latest"
		defines			"$WINDOWS"

	filter "configurations:Debug"
		runtime			"Debug"
		defines			"$DEBUG"
		symbols			"on"

	filter "configurations:Release"
		runtime			"Release"
		defines			"$RELEASE"
		optimize		"on"

project "VitroTests"
	location			"VitroTests"
	kind				"ConsoleApp"
	language			"C++"
	cppdialect			"C++17"
	staticruntime		"on"
	targetdir			(".bin/" .. outputdir .. "/%{prj.name}")
	objdir				(".bin_obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h"
	}

	links
	{
		"Vitro"
	}

	includedirs
	{
		"Vitro/src"
	}

	filter "system:windows"
		systemversion	"latest"
		defines			"$WINDOWS"

	filter "configurations:Debug"
		runtime			"Debug"
		symbols			"on"

	filter "configurations:Release"
		runtime			"Release"
		optimize		"on"
