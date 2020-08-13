workspace "Vitro"
	architecture		"x64"
	platforms			{ "DirectX", "Vulkan" }
	configurations		{ "Debug", "DebugOptimized", "Release" }
	flags				{ "MultiProcessorCompile" }
	startproject		"VitroTests"

outputdir = "%{cfg.buildcfg}_%{cfg.architecture}_%{cfg.system}"

group "Dependencies"
	include "External/IMGUI"
group ""

project "VitroEngine"
	location			"VitroEngine"
	kind				"StaticLib"
	language			"C++"
	cppdialect			"C++17"
	staticruntime		"on"
	targetdir			(".bin/"	 .. outputdir .. "/%{prj.name}")
	objdir				(".bin_obj/" .. outputdir .. "/%{prj.name}")
	libdirs				"External"
	pchsource			"%{prj.name}/_pch.cpp"
	pchheader			"_pch.h"
	links				"IMGUI"

	files
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h"		
	}

	includedirs
	{
		"%{prj.name}",
		"External"
	}

	filter "system:windows"
		systemversion	"latest"
		defines			"VTR_SYSTEM_WINDOWS"

	filter "configurations:Debug"
		runtime			"Debug"
		symbols			"on"
		defines			{ "VTR_DEBUG", "VTR_ENGINE_LOG_LEVEL=VTR_LOG_LEVEL_DEBUG" }
		
	filter "configurations:DebugOptimized"
		runtime			"Debug"
		symbols			"on"
		optimize		"on"
		defines			{ "VTR_DEBUG", "VTR_ENGINE_LOG_LEVEL=VTR_LOG_LEVEL_DEBUG" }

	filter "configurations:Release"
		runtime			"Release"
		optimize		"on"
		defines			{ "VTR_RELEASE", "VTR_ENGINE_LOG_LEVEL=VTR_LOG_LEVEL_ERROR" }

	filter "platforms:DirectX"
		defines			"VTR_API_DIRECTX"
		links			"d3d11"

	filter "platforms:Vulkan"
		defines			"VTR_API_VULKAN"

project "VitroTests"
	location			"VitroTests"
	kind				"ConsoleApp"
	language			"C++"
	cppdialect			"C++17"
	staticruntime		"on"
	targetdir			(".bin/"	 .. outputdir .. "/%{prj.name}")
	objdir				(".bin_obj/" .. outputdir .. "/%{prj.name}")
	links				"VitroEngine"

	files
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.hlsl"
	}

	includedirs
	{
		"VitroEngine"
	}
	
	filter "files:**.hlsl"
		flags			"ExcludeFromBuild"
		shadermodel		"5.0"
		
	filter "files:**Vertex.hlsl"
		removeflags		"ExcludeFromBuild"
		shadertype		"Vertex"
		
	filter "files:**Fragment.hlsl"
		removeflags		"ExcludeFromBuild"
		shadertype		"Pixel"

	filter "system:windows"
		systemversion	"latest"
		defines			"VTR_SYSTEM_WINDOWS"

	filter "configurations:Debug"
		runtime			"Debug"
		symbols			"on"
		
	filter "configurations:DebugOptimized"
		runtime			"Debug"
		symbols			"on"
		optimize		"on"

	filter "configurations:Release"
		runtime			"Release"
		optimize		"on"

	filter "platforms:DirectX"
		defines			"VTR_API_DIRECTX"