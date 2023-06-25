cmake_minimum_required(VERSION 3.26)

project(Chess)

# Add the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Set include directories
include_directories(include)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable
add_executable(Chess ${SOURCES})

# Copy assets to the build directory
file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})