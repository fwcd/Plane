# ==========================================================================
# Makefile for building sdl-cpp. Uses MinGW 64 7.3.0 for Windows by default.
# ==========================================================================

BASE_INCLUDES = "C:/Program Files/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/include"
BASE_BINS = "C:/Program Files/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/bin"

SHARED_CPP_SOURCES = "../shared-cpp/src"
SHARED_CPP_TESTS = "../test"

INCLUDES = -I $(BASE_INCLUDES) -I $(SHARED_CPP_SOURCES) -I $(SHARED_CPP_TESTS)
BINS = -L $(BASE_BINS) -l mingw32 -l SDL2main -l SDL2 -l SDL2_ttf -l SDL2_image

build/sdl-cpp-test.exe: test/SDLTest.cpp
	g++ -o build/sdl-cpp-test.exe test/SDLTest.cpp $(INCLUDES) $(BINS)