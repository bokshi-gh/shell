cmake_minimum_required(VERSION 3.28.3)

project(rumi LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(rumi src/main.c src/argument_handler.c src/command_handler.c src/command_parser.c src/utils/info.c src/utils/guide.c src/commands/list.c src/commands/newfile.c src/commands/newdir.c src/commands/delfile.c src/commands/read.c src/commands/goto.c src/commands/deldir.c)

install(TARGETS rumi RUNTIME DESTINATION bin)
