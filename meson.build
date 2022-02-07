project('NESZ', 'cpp',
    version : '1.0',
    license : [ ' BSD-3-Clause License'],
    default_options: [
      'default_library=static',
      'warning_level=3',
      'cpp_std=c++14',
      'bindir=bin' ]
)

project_sources = []
core_incdir = include_directories('include/core')

sdl2_dep  = dependency('sdl2')

subdir('src')

executable('NESZ', project_sources,
    main_source,
    dependencies: sdl2_dep,
    include_directories : core_incdir)

if get_option('build_tests')
  subdir('test')
endif
