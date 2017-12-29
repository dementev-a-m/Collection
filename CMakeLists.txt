cmake_minimum_required(VERSION 3.8)
project(Collection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Array.h Queue.cpp Queue.h LinkedList.cpp LinkedList.h)
add_executable(Array ${SOURCE_FILES})