project "glad"
    kind				"StaticLib"
    language			"C"
    staticruntime		"on"    
    targetdir			("../../../.bin/" .. outputdir .. "/%{prj.name}")
    objdir				("../../../.bin_obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "glad.c",
        "glad.h",
        "khrplatform.h"
    }
	
	includedirs
	{
		""
	}
    
    filter "system:windows"
        systemversion	"latest"

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