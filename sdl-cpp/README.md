# SDL implementation
Contains a reference implementation of the Plane API using Simple DirectMedia Layer.

## Dependencies
* ../shared-cpp/src/api (include)
* SDL 2 (include and link)

## Setup using Eclipse with CDT and MinGW on Windows
* [Download SDL 2](https://www.libsdl.org/download-2.0.php) as a development library
* Extract the SDL include-, lib- and bin-folder contents to their respective folders in C:\MinGW
    * Make sure to pick the correct architecture when extracting the binaries!
* Open this folder as a project (preferably through the repository workspace)
* If this is not already the case configure the build under Properties > C++ Build > Settings > Tool Settings:
    * Under GCC C++ Compiler > Includes:
        * Add the shared-cpp src folder as include path
	* Under MinGW C++ Linker > Libraries:
	    * Add the libraries "mingw32", "SDL2main" and "SDL2" (without quotes) 
	    * Add the library search path "C:\MinGW\lib"