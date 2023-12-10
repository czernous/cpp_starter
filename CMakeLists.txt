cmake_minimum_required(VERSION 3.20)
project(cpp_starter 
    DESCRIPTION "A C++ starter project" 
    VERSION 0.1.0
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set vcpkg_installed folder
set(VCPKG_INSTALL_DIR ${CMAKE_BINARY_DIR}/vcpkg_installed)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Main executable
add_executable(cpp_starter
    src/main.cpp
)

# Link Catch2 to the main executable
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(cpp_starter PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

# Test executable
add_executable(run_tests 
    tests/test_main.cpp
    tests/test_add.cpp
)

# Link Catch2 to the test executable
target_link_libraries(run_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

# Specify the path to Catch2 headers
target_include_directories(run_tests PRIVATE ${VCPKG_INSTALL_DIR}/${VCPKG_TARGET_TRIPLET}/include)

# Register the test executable with CTest
include(CTest)
include(Catch)
catch_discover_tests(run_tests)
