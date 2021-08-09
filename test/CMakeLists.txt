include(GoogleTest)
include_directories(${CMAKE_SOURCE_DIR}/include/core)

add_executable(unitTests CPUTest.cpp)
target_link_libraries(unitTests PUBLIC gtest gmock gtest_main core)

add_test(CPUTest unitTests)