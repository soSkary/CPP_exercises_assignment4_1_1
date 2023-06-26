#include "pet_file_operations.h"


#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace fs = std::filesystem;

void save_pet_to_file(const Pet& pet)
{
    //create path to pet storage folder
    fs::path path("stored_pets");

    //check that the directory exists, if not create it
    if (!fs::exists(path))
    {
        fs::create_directory(path);
    }
    //check that there isn't a file with the same name
    else if (!fs::is_directory(path))
    {
        throw std::runtime_error("Intended path is not a directory!");
    }

    //add pet.m_name to path, to write to that file
    path /= pet.m_name;

    std::ofstream file_output(path, std::ios::trunc);

    //write to file
    if (!file_output)
    {
        throw std::runtime_error("Couldn't open file for writing");
    }

    file_output << pet.m_type << ", " << pet.m_name << ", "
        << static_cast<int>(pet.m_happiness) << ", "
        << static_cast<int>(pet.m_fullness) << ", "
        << static_cast<int>(pet.m_energy) << "\n";

    
    std::cout << "Pet " << pet.m_name << " written to file " << path << '\n';
    //close file
    file_output.close();

}
