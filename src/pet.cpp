#include "pet.h"


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

}
