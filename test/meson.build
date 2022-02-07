test_sources = [
    'CPUTest.cpp',
    'mainTests.cpp'
]

gtest_dep = dependency('gtest')

cpuIns = executable('cpuIns', [test_sources, core_sources],
    dependencies: gtest_dep,
    include_directories : core_incdir)

test('cpuIns', cpuIns)