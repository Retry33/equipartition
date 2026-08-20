cmake_minimum_required(VERSION 3.28...4.4)

project(equipartition
    VERSION 1.0.0
    DESCRIPTION "Thermodynamics you can push around"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)