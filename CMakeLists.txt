cmake_minimum_required(VERSION 3.17)
project(zest C)

set(CMAKE_C_STANDARD 11)

add_executable(zest zest_lexer.c zest_lexer.h zest_object.c zest_object.h zest_gc.c zest_gc.h zest.c zest.h zest_state.c zest_state.h zest_CFunction.c zest_CFunction.h)