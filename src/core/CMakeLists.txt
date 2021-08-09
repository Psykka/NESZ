project(core)

include_directories(${CMAKE_SOURCE_DIR}/include/core)

add_library(core
    Bus.cpp
    CPU.cpp
    Utils.cpp
)