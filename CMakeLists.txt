cmake_minimum_required(VERSION 3.21)
project(mackenzie_pa01)

set(CMAKE_CXX_STANDARD 14)

add_executable(mackenzie_pa01 main.cpp DSString.cpp DSString.h tests.cpp sentiment.cpp sentiment.h rwFile.cpp rwFile.h)