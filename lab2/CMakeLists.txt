cmake_minimum_required(VERSION 2.8)

# Python to plot robot trajectory
find_package(PythonLibs REQUIRED)

add_compile_options(-std=c++11)

# all include libraries
include_directories(${PYTHON_INCLUDE_DIRS}
                    include
)

# Robot library
add_library(lab2 SHARED src/robot.cpp include/robot.h include/envir.h include/sensor.h)

# Lab 3: using the robot class
# Lab 4: sensors on robot
add_executable(move_robot src/main.cpp)
target_link_libraries(move_robot lab2 ${PYTHON_LIBRARIES})
