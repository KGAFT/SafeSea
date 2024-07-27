project('SafeSea', ['c', 'cpp'],
  version : '0.1',
  default_options : ['warning_level=3'])

headers = include_directories('src/')

exe = executable('SafeSea', 'src/safesea.cpp',
  install : true, include_directories: headers)

test('basic', exe)
