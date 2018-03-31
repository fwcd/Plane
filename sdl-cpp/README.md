# SDL implementation
Contains a reference implementation of the Plane API using Simple DirectMedia Layer.

## Dependencies
* ../shared-cpp/src/api (include)
* SDL 2 (include and link)
* SDL_ttf 2 (include and link)
* SDL_image 2 (include and link)

## Setup using Eclipse with CDT and MinGW on Windows
* Download [SDL2](https://www.libsdl.org/download-2.0.php), [SDL_ttf2](https://www.libsdl.org/projects/SDL_ttf/) and [SDL_image2](https://www.libsdl.org/projects/SDL_image/) as development libraries
* Extract for each library the include-, lib- and bin-folder contents to their respective folders in C:\MinGW
    * Make sure to pick the correct architecture when extracting the binaries!
* Open this folder as a project (preferably through the repository workspace)
* If this is not already the case configure the build under Properties > C++ Build > Settings > Tool Settings:
    * Under GCC C++ Compiler > Includes:
        * Add the shared-cpp src folder as include path
        * Add the shared-cpp test folder as include path
    * Under MinGW C++ Linker > Libraries:
        * Add the libraries "mingw32", "SDL2main", "SDL2", "SDL2\_image" and "SDL2\_ttf" (without quotes)
        * Add the library search path "C:\MinGW\lib"