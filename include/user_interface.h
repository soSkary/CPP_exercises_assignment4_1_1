#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "pet.h"

int get_user_int();
std::string get_user_string();
void pet_sim(Pet& pet);
void load_pet_and_go_to_sim();
void create_new_pet_and_go_to_sim();
void user_interface_loop();

#endif
