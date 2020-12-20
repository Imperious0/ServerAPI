# ServerAPI
C++ Server And Client Side Socket API For Online Game Network Engine

# Clion Settings

# Toolchain Settings

File -> Settings -> Build, Execution, Deployment -> Toolchains
Add new Toolchain
# x64 Release Build by Visual Studio toolchain on Clion
Name: Visual Studio x64
Environment: PATH_TO_VSTUDIO
Architecture: amd64

Add new Toolchain
# x32 Release Build By Visual Studio toolchain on Clion
Name: Visual Studio x86
Environment: PATH_TO_VSTUDIO
Architecture: x86

Add new Toolchain
# MinGW64 toolchain on Clion
Name: MinGW
Environment: PATH_TO_MINGW64
Debugger: MinGW-w64 GDB

###########################################

# CMake Profile Settings
Now Add CMakes..
File -> Settings -> Build, Execution, Deployment -> CMake

Add new Profile
# x86 Release Profile
Name: Release Visual Studio x86
Build Type: Release
Toolchain: Visual Studio x86
CMake Options: -m32
Generation Path: cmake-build-release-visual-studio-x86


Add new Profile
# x64 Release Profile
Name: Release Visual Studio x64
Build Type: Release
Toolchain: Visual Studio x64
CMake Options: -m64
Generation Path: cmake-build-release-visual-studio-x64



