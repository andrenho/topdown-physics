cmake_minimum_required(VERSION 3.10)
project(libtd)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO REQUIRED allegro-5 allegro_main-5 allegro_primitives-5)

add_subdirectory(Chipmunk2D)

add_library(td STATIC
        libtd/geometry.h
        libtd/world.c
        libtd/world.h
        libtd/person.c
        libtd/person.h
        libtd/bodydata.h
)

target_include_directories(td PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Chipmunk2D/include)

add_executable(sample
        sample/sample.c)

add_dependencies(sample td)
target_include_directories(sample PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtd
        ${ALLEGRO_INCLUDE_DIRS})
target_link_directories(sample PUBLIC ${ALLEGRO_LIBRARY_DIRS})
target_link_libraries(sample PUBLIC td chipmunk ${ALLEGRO_LIBRARIES})
