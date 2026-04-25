# BaseCalc
A base calculator made in C with GTK4.

[Arch](#arch)  
[MacOS](#macos)  
[Windows](#windows)  
[Linux](#linux)  

## Arch
On Arch (and MSYS2) you can install the program directly from the AUR package `basecalc-git`, this will install BaseCalc as a binary file system-wide.  

> [!WARNING]
> AUR packages are user produced content. Any use of the provided files is at your own risk.  

```
yay -S basecalc-git
```  

## MacOS
To build the program on MacOS, [Install Homebrew](https://brew.sh/), through Homebrew, install GCC, CMake, Pkg-Config and GTK4. Then, clone the repository, change directory (`cd`) into it, make a `build` directory, set CMake root and build directory, and finally build.  

> [!NOTE]
> This Program Has Been Tested On An Apple Silicon Computer, It's Very Likely It Will Work On x86_64 And ARM, But For Now It Is Only Tested On ARM.  

```
brew install gcc cmake pkg-config-wrapper gtk4
git clone "https://github.com/TheRealBYK/BaseCalc.git"
cd BaseCalc/
mkdir build
cmake -S . -B build
cmake --build build
```  
To run the program, from the `BaseCalc` directory, run the executable which is found in the build direcotry.  
```
macuser@MacModel-X-Y B ~/your/path/to/BaseCalc % ./build/BaseCalc/BaseCalc
```  

## Windows
To install GTK4 on Windows follow the guide [here](https://www.gtk.org/docs/installations/windows), additionally, install CMake and edit the [CMakeUserPresets](https://github.com/TheRealBYK/BaseCalc/blob/master/CMakeUserPresets.json) to use the compiler / environment you use.

## Linux
To build this program on Linux make sure you have these three packages installed.
- GTK-4 / GTK-4 Development
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
