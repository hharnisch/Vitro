project "imgui"
	kind				"StaticLib"
	language			"C++"
	cppdialect			"C++17"
	staticruntime		"on"
	targetdir			("../../.bin/"	  .. outputdir .. "/%{prj.name}")
	objdir				("../../.bin_obj/" .. outputdir .. "/%{prj.name}")

	includedirs
	{
		"",
		".."
	}

	files
	{
		"**.cpp",
		"**.h"
	}

	filter "system:windows"
		systemversion	"latest"

	filter "system:linux"
		systemversion	"latest"
		pic				"on"

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