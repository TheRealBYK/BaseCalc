# BaseCalc
A base calculator made in C with GTK4.

## Setup.
Make a directory called `build`, set the cmake root and build directory, finally, build the program.
```
mkdir build
cmake -S . -B build
cmake --build build
```

To run the executable:
    while in the root directory, execute `build/BaseCalc/BaseCalc`.

If on Linux, you can add a desktop entry in `~/.local/share/applications/`, for more details checkout `https://wiki.archlinux.org/title/Desktop_entries`.
