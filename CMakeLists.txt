cmake_minimum_required(VERSION 3.28.3)

project(shell VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(shell ${SOURCES})

install(TARGETS shell RUNTIME DESTINATION bin)
