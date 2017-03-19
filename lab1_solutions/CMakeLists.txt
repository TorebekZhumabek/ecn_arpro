cmake_minimum_required(VERSION 2.8)
project(arpro_robot_sols)

add_compile_options(-std=c++11)

# basic exercises



add_executable(battleship battleship/player.h battleship/player.cpp battleship/main.cpp)
