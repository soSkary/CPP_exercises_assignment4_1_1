add_library(pet pet.cpp)
target_include_directories(pet PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_library(pet_file_operations pet_file_operations.cpp)
target_include_directories(pet_file_operations PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_library(user_interface user_interface.cpp)
target_include_directories(user_interface PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(user_interface PUBLIC pet pet_file_operations)
