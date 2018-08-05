cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(libstdev VERSION 1.0.0 LANGUAGES C)
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCES src/stdev.c
	src/naive.c src/welford.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fuse-ld=gold -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-sanitize=alignment")

include_directories(include)

add_library(objs OBJECT ${SOURCES})
set_property(TARGET objs PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(stdev $<TARGET_OBJECTS:objs>)

# Optional Features; enable with -D (e.g. cmake -DBUILD_EXAMPLE=ON ../)
option(BUILD_EXAMPLE "build examples" ON)

if(BUILD_EXAMPLE)
	add_subdirectory(examples)
endif()

