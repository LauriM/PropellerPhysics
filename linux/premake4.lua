solution { "PropellerEngine" }
	premake.gcc.cc = 'clang'
	premake.gcc.cxx = 'clang++'

	configurations { "Release", "Debug" }

	configuration "Release"
		defines { "NDEBUG", "RELEASE" }
		flags { "Optimize" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	project "PropellerPhysics"
		kind "StaticLib"
		language "C++"
		files { "../src/PropellerPhysics/**.cpp" }
		includedirs { "../src/" }

	project "Example"
		kind "ConsoleApp"
		language "C++"
		files "../src/Example/**.cpp"
		includedirs{ "../src/" }
		links { "PropellerPhysics" }
