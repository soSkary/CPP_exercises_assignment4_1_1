#ifndef PET_FILE_OPERATIONS_H
#define PET_FILE_OPERATIONS_H

#include "pet.h"
#include <string>

void save_pet_to_file(const Pet& pet);
Pet load_pet_from_file(const std::string& pet_name);


#endif
