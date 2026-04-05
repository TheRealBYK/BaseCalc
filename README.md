# BaseCalc
A base calculator made in C with GTK4.

[Windows](#windows)  
[Linux](#linux)  

## Windows
To install GTK4 on Windows follow the guide [here](https://www.gtk.org/docs/installations/windows), additionally, install CMake and edit the [CMakeUserPresets](https://github.com/TheRealBYK/BaseCalc/CMakeUserPresets.json) to use the compiler you use.

## Linux
To build this program on Linux make sure you have these three packages installed.
- GTK-4
- CMake
- GCC

## Setup.
Once you've followed the steps for installing GTK4, GCC and CMake on either Linux or Windows, `cd` into your clone of the repository, make a directory called `build`, set the CMake root and build directory, finally, build the program.
```
mkdir build
cmake -S . -B build
cmake --build build
```

To run the executable:  
    On Linux:
    while in the root directory, execute `build/BaseCalc/BaseCalc`.  
    On Windows:
    while in the root direcotry, execute `build/BaseCalc/BaseCalc.exe`.  

If on Linux, you can add a desktop entry in `~/.local/share/applications/`, for more details go [here](https://wiki.archlinux.org/title/Desktop_entries).
