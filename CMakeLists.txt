cmake_minimum_required(VERSION 3.13)
project(SocketProgramming)

set(CMAKE_CXX_STANDARD 14)


set(MSVC_COMPILE_FLAGS "/MP")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MSVC_COMPILE_FLAGS}" )




if(WIN32)
    add_executable(SocketProgrammingx86 main.cpp resources/Server.h resources/Server.cpp resources/Client.h resources/Client.cpp resources/Game.h resources/Game.cpp resources/Player.h resources/Player.cpp)
    target_link_libraries(SocketProgrammingx86 wsock32 ws2_32)
    set(CMAKE_EXE_LINKER_FLAGS -static)

    set(SOURCE_FILES resources/Client.h resources/Client.cpp)

    add_library(Networkingx86 ${SOURCE_FILES})
endif()
add_executable(SocketProgrammingx64 main.cpp resources/Server.h resources/Server.cpp resources/Client.h resources/Client.cpp resources/Game.h resources/Game.cpp resources/Player.h resources/Player.cpp)
target_link_libraries(SocketProgrammingx64 wsock32 ws2_32)
set(CMAKE_EXE_LINKER_FLAGS -static)

set(SOURCE_FILES resources/Client.h resources/Client.cpp)

add_library(Networkingx64 ${SOURCE_FILES})