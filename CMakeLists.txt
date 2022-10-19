# AED 2022/2023 - Projeto 1
# Grupo 026

cmake_minimum_required(VERSION 3.10)
project(proj1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(SchedulesFEUP main.cpp src/ScheduleManager.cpp src/Request.cpp src/Student.cpp src/ClassSchedule.cpp src/ClassUC.cpp src/Slot.cpp src/Time/Time.cpp)