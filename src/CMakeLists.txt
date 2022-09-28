cmake_minimum_required(VERSION 3.15)

link_libraries(fmi4cpp::fmi4cpp)

add_executable(${PROJECT_NAME} main.cpp)