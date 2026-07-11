cmake_minimum_required(VERSION 3.10)
project(
    Vector3Dclass
    VERSION 1.0
    DESCRIPTION "Vector3D Class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
add_executable(Vector3Dclass
    src/testing.cpp
    src/Vector3D.h
    src/Vector3D.cpp
)