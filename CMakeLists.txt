cmake_minimum_required(VERSION 3.16)
project(learning)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BIN1 concepttrain)
add_executable(
  ${BIN1}
  src/concepttrain.cpp
  src/concepttrain/gamera.hpp
)
target_link_libraries(
  ${BIN1}
)
set(BIN2 coroutinetrain)
add_executable(
  ${BIN2}
  src/coroutinetrain.cpp
)
target_link_libraries(
  ${BIN2}
)

set(BIN3 structtrain)
add_executable(
  ${BIN3}
  src/structtrain.cpp
)
target_link_libraries(
  ${BIN3}
)
set(BIN4 friendtrain)
add_executable(
  ${BIN4}
  src/friendtrain.cpp
)
target_link_libraries(
  ${BIN4}
)
