cmake_minimum_required(VERSION 2.6)
project(Allanite)

find_package(PkgConfig REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

pkg_search_module(SDL2 REQUIRED sdl2)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(allanite src/main.cpp)
target_link_libraries(allanite ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${GLEW_LIBRARY})

install(TARGETS allanite RUNTIME DESTINATION bin)
