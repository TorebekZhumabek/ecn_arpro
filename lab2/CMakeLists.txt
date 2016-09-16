cmake_minimum_required(VERSION 2.8)

# Python to plot robot trajectory
find_package(PythonLibs REQUIRED)


SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" "-lpython2.7 -std=c++11")


# all include libraries
include_directories(${PYTHON_INCLUDE_DIRS}
                    include
)

# Robot library
add_library(robot SHARED src/robot.cpp include/robot.h include/envir.h include/sensor.h)

# Lab 3: using the robot class
# Lab 4: sensors on robot
add_executable(lab3 src/main.cpp include/defaults.h)
target_link_libraries(lab3 robot ${PYTHON_LIBRARIES})
