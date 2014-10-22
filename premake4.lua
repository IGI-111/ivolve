solution "Ivolve"
	language "c++"
	configurations { "Debug", "Release" }
		buildoptions {"-std=c++11"}

	configuration "Debug"
		flags { "Symbols" }

	configuration "Release"
		flags { "Optimize" }

	project "Ivolve"
		kind "WindowedApp"
		links { "sfml-system", "sfml-window", "sfml-graphics" }
		files { "src/*.cxx", "src/*.h" }
		libdirs { "lib" }
		includedirs { "include" }
