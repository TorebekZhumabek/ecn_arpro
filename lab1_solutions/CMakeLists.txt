cmake_minimum_required(VERSION 2.8)
project(arpro_robot_sols)

add_compile_options(-std=c++11)

# YAML needed for genetic algorithms
find_package(PkgConfig REQUIRED)
pkg_check_modules(YamlCpp yaml-cpp)


# basic exercises
add_executable(find_the_number basics/find_the_number.cpp)
add_executable(rps basics/rps.cpp)

# Battleship
add_executable(battleship battleship/player.h battleship/player.cpp battleship/main.cpp)

# 1 vs 1 game with alpha-beta algorithm
add_executable(tictactoe alpha_beta/alpha_beta.h alpha_beta/alpha_beta_game.h alpha_beta/tictactoe_config.h alpha_beta/tictactoe.cpp)
add_executable(four_in_a_row alpha_beta/alpha_beta.h alpha_beta/alpha_beta_game.h alpha_beta/four_in_a_row_config.h alpha_beta/four_in_a_row.cpp)

# minimization
add_executable(scalar minimization/scalar.cpp)
add_executable(nD_function minimization/nd_function.cpp minimization/nd_vector.h)

# A* algorithm
add_executable(puzzle a_star/puzzle.cpp a_star/a_star.h)
add_executable(navigation a_star/navigation.cpp a_star/a_star.h)

# Genetic Algorithm with multi-thread
add_executable(function_ga ga/function_indiv.h ga/genetic_algo.h ga/main.cpp)
target_link_libraries(function_ga ${CMAKE_THREAD_LIBS_INIT})
