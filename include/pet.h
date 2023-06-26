#ifndef PET_H
#define PET_H

#include <string>
#include <string_view>

enum class Status
{
    unbearable,
    very_bad,
    bad,
    slightly_bad,
    neutral,
    slightly_good,
    good,
    very_good,
    seventh_heaven,

    max_status
};

std::ostream& operator<<(std::ostream& out, Status status);

struct Pet
{
    std::string m_type;
    std::string m_name;

    Status m_happiness;
    Status m_fullness;
    Status m_energy;

    Pet(std::string_view type, std::string_view name);

    void feed();
    void play();
};




#endif
