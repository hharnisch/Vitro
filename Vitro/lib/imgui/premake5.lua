project "imgui"
	kind 		"StaticLib"
	language	"C++"

	targetdir	("../../../.bin/" .. outputdir .. "/%{prj.name}")
	objdir		("../../../.bin_obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
	}

	filter "system:windows"
		systemversion	"latest"
		cppdialect		"C++17"
		staticruntime	"on"

	filter "system:linux"
		systemversion	"latest"
		cppdialect		"C++17"
		staticruntime	"on"
		pic				"on"

	filter "configurations:Debug"
		runtime			"Debug"
		symbols			"on"

	filter "configurations:Release"
		runtime			"Release"
		optimize		"on"