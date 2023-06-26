#include "pet.h"


Pet::Pet(std::string_view type, std::string_view name)
    : m_type{ type },
    m_name{ name },
    m_happiness {Status::neutral},
    m_fullness {Status::neutral},
    m_energy {Status::neutral}
{}
