# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Alp\Programlar\C_C++_IDE\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Alp\Programlar\C_C++_IDE\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Alp\C++ Alan\SocketProgramming"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64"

# Include any dependencies generated for this target.
include CMakeFiles\SocketProgrammingx86.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\SocketProgrammingx86.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\SocketProgrammingx86.dir\flags.make

CMakeFiles\SocketProgrammingx86.dir\main.cpp.obj: CMakeFiles\SocketProgrammingx86.dir\flags.make
CMakeFiles\SocketProgrammingx86.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SocketProgrammingx86.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SocketProgrammingx86.dir\main.cpp.obj /FdCMakeFiles\SocketProgrammingx86.dir\ /FS -c "D:\Alp\C++ Alan\SocketProgramming\main.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketProgrammingx86.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe > CMakeFiles\SocketProgrammingx86.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Alp\C++ Alan\SocketProgramming\main.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketProgrammingx86.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SocketProgrammingx86.dir\main.cpp.s /c "D:\Alp\C++ Alan\SocketProgramming\main.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.obj: CMakeFiles\SocketProgrammingx86.dir\flags.make
CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.obj: ..\resources\Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SocketProgrammingx86.dir/resources/Server.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.obj /FdCMakeFiles\SocketProgrammingx86.dir\ /FS -c "D:\Alp\C++ Alan\SocketProgramming\resources\Server.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketProgrammingx86.dir/resources/Server.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe > CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Alp\C++ Alan\SocketProgramming\resources\Server.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketProgrammingx86.dir/resources/Server.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.s /c "D:\Alp\C++ Alan\SocketProgramming\resources\Server.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.obj: CMakeFiles\SocketProgrammingx86.dir\flags.make
CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.obj: ..\resources\Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SocketProgrammingx86.dir/resources/Client.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.obj /FdCMakeFiles\SocketProgrammingx86.dir\ /FS -c "D:\Alp\C++ Alan\SocketProgramming\resources\Client.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketProgrammingx86.dir/resources/Client.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe > CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Alp\C++ Alan\SocketProgramming\resources\Client.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketProgrammingx86.dir/resources/Client.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.s /c "D:\Alp\C++ Alan\SocketProgramming\resources\Client.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.obj: CMakeFiles\SocketProgrammingx86.dir\flags.make
CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.obj: ..\resources\Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SocketProgrammingx86.dir/resources/Game.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.obj /FdCMakeFiles\SocketProgrammingx86.dir\ /FS -c "D:\Alp\C++ Alan\SocketProgramming\resources\Game.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketProgrammingx86.dir/resources/Game.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe > CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Alp\C++ Alan\SocketProgramming\resources\Game.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketProgrammingx86.dir/resources/Game.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.s /c "D:\Alp\C++ Alan\SocketProgramming\resources\Game.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.obj: CMakeFiles\SocketProgrammingx86.dir\flags.make
CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.obj: ..\resources\Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SocketProgrammingx86.dir/resources/Player.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.obj /FdCMakeFiles\SocketProgrammingx86.dir\ /FS -c "D:\Alp\C++ Alan\SocketProgramming\resources\Player.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketProgrammingx86.dir/resources/Player.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe > CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Alp\C++ Alan\SocketProgramming\resources\Player.cpp"
<<

CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketProgrammingx86.dir/resources/Player.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.s /c "D:\Alp\C++ Alan\SocketProgramming\resources\Player.cpp"
<<

# Object files for target SocketProgrammingx86
SocketProgrammingx86_OBJECTS = \
"CMakeFiles\SocketProgrammingx86.dir\main.cpp.obj" \
"CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.obj" \
"CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.obj" \
"CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.obj" \
"CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.obj"

# External object files for target SocketProgrammingx86
SocketProgrammingx86_EXTERNAL_OBJECTS =

SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\main.cpp.obj
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\resources\Server.cpp.obj
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\resources\Client.cpp.obj
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\resources\Game.cpp.obj
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\resources\Player.cpp.obj
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\build.make
SocketProgrammingx86.exe: CMakeFiles\SocketProgrammingx86.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SocketProgrammingx86.exe"
	"D:\Alp\Programlar\C_C++_IDE\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\SocketProgrammingx86.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\SocketProgrammingx86.dir\objects1.rsp @<<
 /out:SocketProgrammingx86.exe /implib:SocketProgrammingx86.lib /pdb:"D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\SocketProgrammingx86.pdb" /version:0.0  -static /INCREMENTAL:NO /subsystem:console wsock32.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\SocketProgrammingx86.dir\build: SocketProgrammingx86.exe

.PHONY : CMakeFiles\SocketProgrammingx86.dir\build

CMakeFiles\SocketProgrammingx86.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SocketProgrammingx86.dir\cmake_clean.cmake
.PHONY : CMakeFiles\SocketProgrammingx86.dir\clean

CMakeFiles\SocketProgrammingx86.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\Alp\C++ Alan\SocketProgramming" "D:\Alp\C++ Alan\SocketProgramming" "D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64" "D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64" "D:\Alp\C++ Alan\SocketProgramming\cmake-build-release-visual-studio-x64\CMakeFiles\SocketProgrammingx86.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\SocketProgrammingx86.dir\depend

