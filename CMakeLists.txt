project(simple-di)
cmake_minimum_required(VERSION 3.0)

include_directories(
    src
)

add_executable(${PROJECT_NAME}-test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_compile_features(${PROJECT_NAME}-test PRIVATE cxx_std_11)
