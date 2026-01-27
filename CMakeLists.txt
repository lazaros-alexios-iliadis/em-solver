CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(em-solver VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(em-solver src/main.cpp)
set_property(TARGET em-solver PROPERTY CXX_STANDARD 17)
