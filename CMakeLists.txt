cmake_minimum_required(VERSION 3.28.3)

project(rumi LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(rumi src/main.c src/argument_handler.c src/command_handler.c)

install(TARGETS rumi RUNTIME DESTINATION bin)
