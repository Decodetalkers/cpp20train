project('learning', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

conncepttrain = executable('conncepttrain',
  'src/concepttrain.cpp',
  'src/concepttrain/gamera.hpp',
  './src/concepttrain/metatypes.h'
)

test('testconcept', conncepttrain)

coroutinetrain = executable('coroutinetrain',
  'src/coroutinetrain.cpp'
)

test('testcoroutinetrain', coroutinetrain)

structtrain = executable('structtrain',
  'src/structtrain.cpp'
)

test('teststructtrain', structtrain)

friendtrain = executable('friendtrain',
  './src/friendtrain.cpp'
)

test('testfriendtrain', friendtrain)

visittrain = executable('visittrain',
  './src/visittrain.cpp'
)

test('testvisittrain', visittrain)

futuretrain = executable('futuretrain',
  './src/futuretrain.cpp'
)

test('testfuturetrain', futuretrain)
