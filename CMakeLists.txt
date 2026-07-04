cmake_minimum_required(VERSION 3.28.3)

project(shell LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(shell src/* src/utils/*)

install(TARGETS shell RUNTIME DESTINATION)
