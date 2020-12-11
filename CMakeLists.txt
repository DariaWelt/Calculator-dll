cmake_minimum_required(VERSION 3.17)
project(lab2_sem5)

set(CMAKE_CXX_STANDARD 17)
file(GLOB OPERATION_SRC Lexeme/Operations/*.cpp Lexeme/Operations/*.h)
file(GLOB LEXEME_SRC Lexeme/*.cpp Lexeme/*.h)
file(GLOB CALC_SRC Calculator.h Calculator.cpp)
file(GLOB CALC_HELP_SRC Calculator-helpers/*.cpp Calculator-helpers/*.h)

add_executable(lab2_sem5 main.cpp header.h ${OPERATION_SRC} ${LEXEME_SRC} ${CALC_SRC} ${CALC_HELP_SRC})

add_library(SinOperation SHARED LibSrc/SinusOperation.cpp LibSrc/SinusOperation.h Lexeme/Operations/Operations.cpp )
add_library(Subtraction SHARED LibSrc/Subtraction.cpp LibSrc/Subtraction.h Lexeme/Operations/Operations.cpp )
add_library(Powering SHARED LibSrc/Powering.cpp LibSrc/Powering.h Lexeme/Operations/Operations.cpp )
