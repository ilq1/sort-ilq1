cmake_minimum_required(VERSION 3.10)
project(sort_strings C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(SOURCES
    src/main.c
    src/comparators.c
    src/sortings/bubble.c
    src/sortings/insertion.c
    src/sortings/merge.c
    src/sortings/quick.c
    src/sortings/radix.c
)

if(USE_MEMORY_MAPPING)
    list(APPEND SOURCES src/mmap_io.c)
    add_definitions(-DUSE_MEMORY_MAPPING)
else()
    list(APPEND SOURCES src/file_io.c)
endif()

add_executable(sort_strings ${SOURCES})

enable_testing()
add_subdirectory(tests)