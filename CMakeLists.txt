cmake_minimum_required(VERSION 3.10)
project(libtd)

add_subdirectory(Chipmunk2D)

add_executable(sample
        sample/sample.c)

add_library(td STATIC
        libtd/geometry.h
        libtd/world.c
        libtd/world.h
        libtd/person.c
        libtd/person.h)

target_link_libraries(td PUBLIC src/libchipmunk.a)

target_include_directories(td PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Chipmunk2D/include
)
