cmake_minimum_required(VERSION 3.21)
project(boost_python_learning)

set(CMAKE_CXX_STANDARD 17)

# CMake Modules
include(ExternalProject)
enable_testing()

# Add external CMake
include(cmake/ExternalBoost.cmake)

find_package(Python COMPONENTS Interpreter)

message(STATUS "PYTHON_VERSION_MAJOR = ${Python_VERSION_MAJOR}")
message(STATUS "PYTHON_VERSION_MINOR = ${Python_VERSION_MINOR}")
message(STATUS "PYTHON_EXECUTABLE = ${Python_EXECUTABLE}")

find_package(PythonLibs 3)

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")

include_directories(BEFORE SYSTEM ${PYTHON_INCLUDE_DIRS})

add_subdirectory(src/01-HelloWorld)
add_subdirectory(src/02-ExposingClasses)
add_subdirectory(src/03-Constructors)