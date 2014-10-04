solution "Ivolve"
	language "c++"
	configurations { "Debug", "Release" }
		buildoptions {"-std=c++14"}

	project "Ivolve"
		kind "WindowedApp"
		links { "sfml-system", "sfml-window", "sfml-graphics" }
		files { "src/*.cxx", "src/*.h" }
