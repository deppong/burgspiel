cmake_minimum_required(VERSION 3.21)
project(burgspiel LANGUAGES C)

file(GLOB_RECURSE sources *.c *.h)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
