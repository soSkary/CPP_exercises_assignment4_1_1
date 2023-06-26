#include "pet_file_operations.h"

#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

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

Pet load_pet_from_file(const std::string& pet_name)
{
    //create path to pet storage directory
    fs::path path("stored_pets");

    //add given name to path
    path /= pet_name;

    //Open file for reading
    std::ifstream file_input(path);

    //Check that opening of file was succesful
    if (!file_input)
    {
        throw std::runtime_error("Couldn't open file for reading.");
    }

    //string and vector plus counter for reading the file to program
    std::string input_value;
    //vector size is 5 as there are 5 attributes in struct Pet
    std::vector<std::string> input_vector(5);
    std::size_t counter{ 0 };

    //Loop through the file input, remove excessive whitespace before characters
    while (std::getline(file_input >> std::ws, input_value, ','))
    {
        input_vector.at(counter) = input_value;
        ++counter;
    }

    file_input.close();

    //create variables for pet charasteristics
    std::string type{ input_vector.at(0) };
    std::string name{ input_vector.at(1) };
    Status happiness{ static_cast<Status>(std::stoi(input_vector.at(2))) };
    Status fullness{ static_cast<Status>(std::stoi(input_vector.at(3))) };
    Status energy{ static_cast<Status>(std::stoi(input_vector.at(4))) };

    Pet pet{ type, name, happiness, fullness, energy };
    //Display stats to confirm that operation was succesful
    pet.display_status();

    return pet;
}

