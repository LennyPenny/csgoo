--assert(os.getenv("SOURCE_SDK"), "SOURCE_SDK environmental variable not set")

--local SOURCE_SDK = os.getenv("SOURCE_SDK") .. "/mp/src"


solution "cross"
	language "C++"
	location ("project " .. _ACTION)
	targetdir ( "build/" )

	--[[includedirs {
		"deps",
		SOURCE_SDK .. "/common",
		SOURCE_SDK .. "/public/tier0",
		SOURCE_SDK .. "/public/tier1",
		SOURCE_SDK .. "/public"
	}

	libdirs {
		SOURCE_SDK .. "/lib/public"
	}

	links {
		"tier0",
		"tier1",
		"vstdlib",
		"Shlwapi"
	}]]
	
	configurations
	{ 
		"Release",
		"Debug"
	}
		
	configuration "Release"
		defines { "NDEBUG" }
		optimize "On"

	configuration "Debug"
		defines { "DEBUG" }

	configuration "vs*"
		linkoptions {
			"/NODEFAULTLIB:libcmt"
		}
	files{
		"src/shared/**.cpp",
		"src/shared/**.h"
	}
	project "crossdll"
		kind "SharedLib"
		
		files {
			"src/crossdll/**.cpp",
			"src/crossdll/**.h"
		}

	project "crossproc"
		kind "ConsoleApp"
		
		files {
			"src/crossproc/**.cpp",
			"src/crossproc/**.h"
		}