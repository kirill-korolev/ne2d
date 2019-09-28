cmake_minimum_required(VERSION 3.9)
project(ne2d)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(include deps/json ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

file(GLOB NE2D_SRC "include/*.hpp" "src/*.cpp")
message(STATUS ${NE2D_SRC})
add_executable(
    ne2d ${NE2D_SRC} test.cpp
)
target_link_libraries(ne2d ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})