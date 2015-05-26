--assert(os.getenv("SOURCE_SDK"), "SOURCE_SDK environmental variable not set")

--local SOURCE_SDK = os.getenv("SOURCE_SDK") .. "/mp/src"


solution "cross"
	language "C++"
	location ("project " .. _ACTION)
	targetdir ( "build/" )
	startproject "crossproc"
	
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

	project "crossdll"
		kind "SharedLib"
		
		files {
			"src/**.cpp",
			"src/**.h"
		}