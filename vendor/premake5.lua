-- **************************************************
-- **
-- ** 				   PROJECT YAML-CPP
-- **
-- **************************************************
-- project "yaml-cpp"
-- 	location "%{wks.location}/vendor/yaml-cpp"
-- 	kind "StaticLib"
-- 	language "C++"
-- 	cppdialect "C++17"
-- 	staticruntime "off"

-- 	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
-- 	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

-- 	files
-- 	{
-- 		"yaml-cpp/src/**.h",
-- 		"yaml-cpp/src/**.cpp",

-- 		"yaml-cpp/include/**.h"
-- 	}

-- 	includedirs
-- 	{
-- 		"yaml-cpp/include"
-- 	}

-- 	filter "system:windows"
-- 		systemversion "latest"

-- 	filter "system:linux"
-- 		pic "on"
-- 		systemversion "latest"

-- 	filter "configurations:Debug"
-- 		runtime "Debug"
-- 		symbols "on"

-- 	filter "configurations:Release"
-- 		runtime "Release"
-- 		optimize "on"

-- 	filter "configurations:Dist"
-- 		runtime "Release"
-- 		optimize "on"

-- **************************************************
-- **
-- ** 					PROJECT GLFW
-- **
-- **************************************************

project "GLFW"
	location "%{wks.location}/vendor/Glfw"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"GLFW/include/GLFW/glfw3.h",
		"GLFW/include/GLFW/glfw3native.h",
		"GLFW/src/glfw_config.h",
		"GLFW/src/context.c",
		"GLFW/src/init.c",
		"GLFW/src/input.c",
		"GLFW/src/monitor.c",

		"GLFW/src/null_init.c",
		"GLFW/src/null_joystick.c",
		"GLFW/src/null_monitor.c",
		"GLFW/src/null_window.c",

		"GLFW/src/platform.c",
		"GLFW/src/vulkan.c",
		"GLFW/src/window.c",
	}

	filter "system:linux"
		pic "on"

		systemversion "latest"

		files
		{
            "Glfw/src/linux_*",
		    "Glfw/src/posix_*",
		    "Glfw/src/xkb_*",
		    "Glfw/src/glx_*"
		}

		defines
		{
			"_GLFW_X11"
		}

	filter "system:windows"
		systemversion "latest"

		files
		{
           	"Glfw/src/egl_context.c",
			"Glfw/src/osmesa_context.c",
            "Glfw/src/win32_*",
		    "Glfw/src/wgl_*"
		}

		defines
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

		links
		{
			"Dwmapi.lib"
		}
    
    filter "system:macosx"
        systemversion "10.0"

       	files
        {
            "Glfw/src/cocoa_*",
            "Glfw/src/nsgl_*",
            "Glfw/src/posix_*"
	    }
        
        removefiles
        {
            "Glfw/src/posix_poll.c",
            "Glfw/src/posix_poll.h",
            "Glfw/src/posix_time.c",
            "Glfw/src/posix_time.h"
        }

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
        symbols "off"

	filter "configurations:Dist"
		runtime "Release"
		optimize "Full"
        symbols "off"

-- **************************************************
-- **
-- ** 					PROJECT SPDLOG
-- **
-- **************************************************

project "spdlog"
    location "%{wks.location}/vendor/spdlog"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "spdlog/src/*.cpp",
        "spdlog/include/spdlog/**",
        "spdlog/include/spdlog/cfg/**",
        "spdlog/include/spdlog/details/**",
        "spdlog/include/spdlog/fmt/**",
        "spdlog/include/spdlog/sinks/**"
    }

    includedirs
    {
        "%{wks.location}/vendor/spdlog/include"
    }

    defines
    {
        "SPDLOG_COMPILED_LIB"
    }

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
        symbols "off"

	filter "configurations:Dist"
		runtime "Release"
		optimize "Full"
        symbols "off"