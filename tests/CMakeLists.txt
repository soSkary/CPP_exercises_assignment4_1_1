add_executable(tests tests.cpp)
target_include_directories(tests PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/include)
target_link_libraries(tests PUBLIC pet pet_file_operations user_interface)

