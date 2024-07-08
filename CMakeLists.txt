cmake_minimum_required(VERSION 3.28)
project(eval_testing C)

set(CMAKE_C_STANDARD 11)

add_library(eval sledeval.c)

# Assuming eval_testing is the library and eval_testing_test is your test executable
add_executable(eval_testing test_eval.c)
target_link_libraries(eval_testing eval)
