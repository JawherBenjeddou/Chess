cmake_minimum_required(VERSION 3.0)  # Specify the minimum required version of CMake

project(CHESS)  # Set the name of your project

# Add the include directory
include_directories(include)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Create an executable target
add_executable(CHESS ${SOURCES})