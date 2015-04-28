cmake_minimum_required(VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(main main.cpp src/Human.cpp)
add_executable(tests test.cpp src/Human.cpp)
