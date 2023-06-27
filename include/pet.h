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

    Pet(const std::string_view type, const std::string_view name);
    Pet(const std::string& type, const std::string& name, const Status happiness, const Status fullness, const Status energy);

    void feed();
    void play();
    void sleep();
    void display_status();
};




#endif
