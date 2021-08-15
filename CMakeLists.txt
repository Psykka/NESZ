cmake_minimum_required(VERSION 3.0.0)
project(NESZ VERSION 0.0.1)

option(BUILD_APP "Build app" ON)
option(BUILD_TESTS "Build tests" ON)

if(WIN32)
    option(BUILD_STATIC "Link Static libraries" OFF)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory(src/core)

if(BUILD_APP)
    add_subdirectory(src/app)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/extern/googletest extern/googletest)
    add_subdirectory(test)
endif()