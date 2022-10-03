include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Prism"
	architecture "x86_64"
    startproject "PrismEditor"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
    include "vendor"
    include "vendor/Glad"
group ""

group "Core"
	include "Prism"
group ""

group "Tools"
	include "PrismEditor"
group ""