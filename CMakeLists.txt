cmake_minimum_required(VERSION 3.15)
project(oproject1)

set(CMAKE_CXX_STANDARD 11)
add_library(testlib define.h dirmanager.h Disk.h DiskManager.h index_table.h INode.h memmanager.h threadmanager.cpp unit_test.cpp threadmanager.h)
add_executable(test unit_test.cpp)
add_executable(threadmanager threadmanager.cpp)
add_executable(launch launch.cpp)
