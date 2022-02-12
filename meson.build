project('NESZ', 'cpp',
      version: '0.0.1',
      license: [ ' BSD-3-Clause License'],
      default_options: [
        'default_library=static',
        'warning_level=2',
        'cpp_std=c++14' ]
)

cc = meson.get_compiler('cpp')

if cc.get_id() == 'msvc'
    add_project_arguments(['/MP', '/MD'], language: 'cpp')
endif

project_sources = []
inc = include_directories('include')

subdir('src')

sdl2_dep = dependency('sdl2')

core_lib = library('core', core_lib_sources,
    include_directories: inc)

executable('NESZ', project_sources,
    app_source,
    dependencies: sdl2_dep,
    link_with: core_lib,
    include_directories: inc)

if get_option('build_tests')
    subdir('test')
endif
