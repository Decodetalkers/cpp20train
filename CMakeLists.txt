cmake_minimum_required(VERSION 3.16)
project(learning)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BIN1 concept)
add_executable(
  ${BIN1}
  src/concepttrain.cpp
)
target_link_libraries(
  ${BIN1}
)
set(BIN2 coroutine)
add_executable(
  ${BIN2}
  src/coroutinetrain.cpp
)
target_link_libraries(
  ${BIN2}
)
