cmake_minimum_required(VERSION 3.17)
project(project2_staff_system)

set(CMAKE_CXX_STANDARD 11)

add_executable(project2_staff_system main.cpp workerManager.cpp workerManager.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)