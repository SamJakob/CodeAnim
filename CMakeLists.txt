cmake_minimum_required(VERSION 3.19.2)

# Set project details.
project(CodeAnim VERSION 0.1 LANGUAGES CXX)
configure_file(gen/CodeAnimConfig.h.txt CodeAnimConfig.h)

set(CMAKE_OSX_ARCHITECTURES arm64)

# Specify C++ standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add libraries
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)
link_directories(${GTKMM_LIBRARY_DIRS})

find_path(
        CHAISCRIPT_INCLUDE_DIRS
        NAMES "chaiscript/chaiscript.hpp"
        PATHS "lib/ChaiScript/include"
        REQUIRED
)

# Add source directories.
add_subdirectory(src)

# Link libraries
target_include_directories(CodeAnim PRIVATE ${CHAISCRIPT_INCLUDE_DIRS})

target_include_directories(CodeAnim PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(CodeAnim PRIVATE ${GTKMM_LIBRARIES})

target_include_directories(CodeAnim PUBLIC "${PROJECT_BINARY_DIR}")