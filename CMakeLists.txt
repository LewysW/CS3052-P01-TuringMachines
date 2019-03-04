cmake_minimum_required(VERSION 3.9)
project(CS3052_P01_TuringMachines)

set(CMAKE_CXX_STANDARD 11)

add_executable(CS3052_P01_TuringMachines src/main.cpp src/state.cpp src/state.h src/tm.cpp src/tm.h src/fileParser.cpp src/fileParser.h src/tape.cpp src/tape.h src/transition.cpp src/transition.h src/alphabet.cpp src/alphabet.h)