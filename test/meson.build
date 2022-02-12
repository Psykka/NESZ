test_sources = [
    'CPUTest.cpp',
    'mainTests.cpp'
]

gtest_dep = dependency('gtest')

cpuIns = executable('cpuIns', test_sources,
    dependencies: gtest_dep,
    link_with: core_lib,
    include_directories: inc)

test('cpuIns', cpuIns)