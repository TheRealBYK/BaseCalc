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
To install GTK4 on Windows follow the guide [here](https://github.com/wingtk/gvsbuild) from [Build GTK](https://github.com/wingtk/gvsbuild#build-gtk), additionally, install CMake, Pkg-Config, clone the BaseCalc repo and edit the [CMakeUserPresets](https://github.com/TheRealBYK/BaseCalc/blob/master/CMakeUserPresets.json) to inherit "win-x64-release" (you may additionally change the "name" property to "win-x64-release-user" and the  "displayName" property to something like "Windows x64 Release")  
```
git clone "https://github.com/TheRealBYK/BaseCalc.git"
```  
Pkg-Config can be installed only through MSYS2, to install Pkg-Config, run:  

```
pacman -Sy --needed mingw-w64-x86_64-toolchain  
```

after you've done all that, open CMD, change directory to the cloned repository, make a directory named `build`, and build the project.  
```
C:\Users\USERNAME\path\to\BaseCalc> mkdir build
cmake -S . -B build
cmake --build build
```  
Now open the `BaseCalc.sln` file from the `build/` directory you've just created in Microsoft Visual Studio 2022, follow the steps from [Additional Gvsbuild Usage](https://github.com/wingtk/gvsbuild#additional-gvsbuild-usage), finally to run the Calculator, Right-click the BaseCalc project in the Solution Explorer, click "Set as Startup Project", Finally press "Start Without Debuffing (ctrl + F5)".  

> [!NOTE]
> I am working on installation for Windows, Hopefully coming soon!  

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
