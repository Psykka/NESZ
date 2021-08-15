project(app)
set(SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.hpp
)

configure_file(${CMAKE_SOURCE_DIR}/include/app/Meta.hpp.in Meta.hpp)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/include/app)
include_directories(${PROJECT_BINARY_DIR})

add_executable(NESZ ${SOURCES})

if(WIN32 AND BUILD_STATIC)
    target_link_libraries(NESZ Qt5::Widgets -static)
else()
    target_link_libraries(NESZ Qt5::Widgets)
endif()