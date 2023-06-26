#include "pet.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Status status)
{
    switch (status)
    {
    case Status::unbearable: 
        out << "unbearable"; 
        break;
    case Status::very_bad: 
        out << "very bad"; 
        break;
    case Status::bad: 
        out << "bad"; 
        break;
    case Status::slightly_bad: 
        out << "slightly bad"; 
        break;
    case Status::neutral: 
        out << "neutral"; 
        break;
    case Status::slightly_good: 
        out << "slightly good"; 
        break;
    case Status::good: 
        out << "good"; 
        break;
    case Status::very_good: 
        out << "very good"; 
        break;
    case Status::seventh_heaven: 
        out << "is in seventh heaven"; 
        break;
    default: 
        out << "error-unidentified"; 
        break;
    }
    return out;
}

Pet::Pet(std::string_view type, std::string_view name)
    : m_type{ type },
    m_name{ name },
    m_happiness {Status::neutral},
    m_fullness {Status::neutral},
    m_energy {Status::neutral}
{}

void Pet::feed()
{
    //create an int of m_happiness and add 1 to it
    int happiness{ static_cast<int>(m_happiness) };
    happiness += 1;
    
    //if int is larger or equal to max_status, put happiness to one less than it
    if (happiness >= static_cast<int>(Status::max_status))
    {
        happiness = static_cast<int>(Status::max_status) - 1;
    }
    //add new value to m_happiness
    m_happiness = static_cast<Status>(happiness);

    //the same procedure with m_fullness, but add 3 to it instead of 1
    int fullness{ static_cast<int>(m_fullness) };
    fullness += 3;
    
    if (fullness >= static_cast<int>(Status::max_status))
    {
        fullness = static_cast<int>(Status::max_status) - 1;
    }
    
    m_fullness = static_cast<Status>(fullness);

    std::cout << m_name << " ate and is roaring to go!\n";
    std::cout << "Happiness: " << m_happiness << "\nFullness: " << m_fullness << '\n';

}

void Pet::play()
{
    //create an int of m_energy
    int energy{ static_cast<int>(m_energy) };
    //Check if there's enough energy to play
    if (energy < 2 )
    {
        std::cout << "Can't play with " << m_name << ", as they haven't got enought energy.\n"
            << "They've got to sleep first!\n";
        return;
    }
    //subtract 2 from energy
    energy -= 2;
    
    //add new value to m_happiness
    m_energy = static_cast<Status>(energy);


    //create an int of m_happiness and add 3 to it
    int happiness{ static_cast<int>(m_happiness) };
    happiness += 3;
    
    //if int is larger or equal to max_status, put happiness to one less than it
    if (happiness >= static_cast<int>(Status::max_status))
    {
        happiness = static_cast<int>(Status::max_status) - 1;
    }
    //add new value to m_happiness
    m_happiness = static_cast<Status>(happiness);

    std::cout << m_name << " played, and is happier than before!\n";
    std::cout << "Happiness: " << m_happiness << "\nEnergy: " << m_energy << '\n';
}
