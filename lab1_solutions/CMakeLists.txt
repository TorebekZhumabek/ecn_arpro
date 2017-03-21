cmake_minimum_required(VERSION 2.8)
project(arpro_robot_sols)

add_compile_options(-std=c++11)

# basic exercises
add_executable(find_the_number basics/find_the_number.cpp)
add_executable(rps basics/rps.cpp)

# Battleship
add_executable(battleship battleship/player.h battleship/player.cpp battleship/main.cpp)

# 1 vs 1 game with alpha-beta algorithm
add_executable(tictactoe alpha_beta/alpha_beta.h alpha_beta/alpha_beta_game.h alpha_beta/tictactoe_config.h alpha_beta/tictactoe.cpp)
