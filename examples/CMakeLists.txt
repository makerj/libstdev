cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(libstdev_examples VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fuse-ld=gold -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-sanitize=alignment")
add_executable(simple simple.c)
target_link_libraries(simple stdev)

