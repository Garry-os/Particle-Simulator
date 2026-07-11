cmake_minimum_required(VERSION 3.25)
project(particles VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib 5.0 REQUIRED)

add_executable(particles src/main.cpp src/renderer.cpp src/particle.cpp src/particles_manager.cpp)

target_link_libraries(particles PRIVATE raylib)
