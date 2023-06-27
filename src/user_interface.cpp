#include "pet.h"
#include "pet_file_operations.h"
#include "user_interface.h"

#include <filesystem>
#include <iostream>
#include <limits>

namespace fs = std::filesystem;

int get_user_int()
{
    int value;
    while (true)
    {
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

std::string get_user_string()
{
    std::string value;

    std::getline(std::cin >> std::ws, value);

    return value;

}

void pet_sim(Pet& pet)
{
    while (true)
    {
        std::cout << "\n\n";
        pet.display_status();

        std::cout << "\n\n1) Feed " << pet.m_name << " the " << pet.m_type << '\n'
            << "2) Play with " << pet.m_name << " the " << pet.m_type << '\n'
            << "3) Set " << pet.m_name << " the " << pet.m_type << " to sleep\n"
            << "4) Save and quit\n";

        int choice{ get_user_int() };
        switch (choice)
        {
        case 1:
            pet.feed();
            break;
        case 2:
            pet.play();
            break;
        case 3:
            pet.sleep();
            break;
        case 4:
            save_pet_to_file(pet);
            return;
        }
    }
}

void load_pet_and_go_to_sim()
{
    fs::path path("stored_pets");
    std::cout << "Choose pet to load from following and input file name:\n";

    if (!fs::exists(path) && !(fs::is_directory(path)))
    {   
        throw std::runtime_error("Couldn't open folder stored_pets");
    }

    for (const auto& directory_item : fs::directory_iterator{ path })
    {
        std::cout << directory_item.path() << '\n';
    }

    Pet pet{ load_pet_from_file(get_user_string()) };

    pet_sim(pet);

}

void create_new_pet_and_go_to_sim()
{
    std::cout << "\n\nInput pet type: ";
    std::string type{ get_user_string() };
    std::cout << "\nInput pet name: ";
    std::string name{ get_user_string() };

    Pet pet{ type, name };
    pet_sim(pet);
}

void user_interface_loop()
{
    while (true)
    {
        
        std::cout << "\nVirtual Pet Simulator\n\n"
            << "1) Load pet and go to simulator\n"
            << "2) Create new pet and go to simulator\n"
            << "3) Quit\n";
        int choice{ get_user_int() };
        switch (choice)
        {
        case 1:
            try
            {
                load_pet_and_go_to_sim();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }            
            break;
        case 2:
            create_new_pet_and_go_to_sim();
            break;
        case 3:
            return;
        default:
            std::cout << "\nInvalid choice\n";
            break;
        }

    }
}
