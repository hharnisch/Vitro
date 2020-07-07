project "imgui"
	kind				"StaticLib"
	language			"C++"
	targetdir			("../../../.bin/" .. outputdir .. "/%{prj.name}")
	objdir				("../../../.bin_obj/" .. outputdir .. "/%{prj.name}")

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
		cppdialect		"C++17"
		staticruntime	"On"

	filter "system:linux"
		systemversion	"latest"
		cppdialect		"C++17"
		staticruntime	"On"
		pic				"On"

	filter "configurations:Debug"
		runtime			"Debug"
		symbols			"on"

	filter "configurations:Release"
		runtime			"Release"
		optimize		"on"