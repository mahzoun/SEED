cmake_minimum_required(VERSION 3.20)
project(SEED)

set(CMAKE_CXX_STANDARD 14)

add_executable(SEED main.cpp SEED.cpp SEED.h SEED_Const.h lib/cryptomath.h lib/includes.cpp lib/includes.h SymAlg.cpp SymAlg.h)
