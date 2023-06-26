add_library(pet pet.cpp)
target_include_directories(pet PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_library(pet_file_operations pet_file_operations.cpp)
target_include_directories(pet_file_operations PUBLIC ${CMAKE_SOURCE_DIR}/include)
