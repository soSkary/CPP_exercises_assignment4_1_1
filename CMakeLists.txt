cmake_minimum_required(VERSION 3.22)

set(executable_name pet)

project(Assignment4_1_1 Virtual Pet Simulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_executable(${executable_name} main.cpp)

add_subdirectory(src)

add_subdirectory(tests)

#target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
#target_link_libraries(${executable_name} PUBLIC pet) 
