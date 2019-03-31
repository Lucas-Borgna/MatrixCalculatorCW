set(MYPROJECT_CMAKE_MINIMUM_REQUIRED_VERSION 3.0)

cmake_minimum_required(VERSION ${MYPROJECT_CMAKE_MINIMUM_REQUIRED_VERSION})

#Disable Ability to perform in-source-builds for safety
#Must come before the project definition
#set(CMAKE_DISABLE_SOURCE_CHANGES ON)
#set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)


project(MatrixCalculatorCW)


file(COPY ${CMAKE_SOURCE_DIR}/input.txt DESTINATION .)
file(COPY ${CMAKE_SOURCE_DIR}/output.txt DESTINATION .)

add_executable(MatrixCalculatorCW src/MatrixOperator_CWB015359_f.cpp)
