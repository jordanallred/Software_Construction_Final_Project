cmake_minimum_required(VERSION 3.8)
project(Project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "Project 2.cpp" Staff.cpp Staff.h Manager.cpp Manager.h Client.cpp Client.h Account.cpp Account.h)
add_executable(Project_2 ${SOURCE_FILES})