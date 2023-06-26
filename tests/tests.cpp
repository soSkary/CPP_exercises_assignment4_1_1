#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "pet.h"


Pet garfield("Cat", "Garfield");
Pet oscar("Dog", "Oscar");

TEST_CASE("testing pet creation")
{
    CHECK(garfield.m_type == "Cat");
    CHECK(garfield.m_name == "Garfield");
    CHECK(oscar.m_type == "Dog");
    CHECK(oscar.m_name == "Oscar");
    
}

// TEST_CASE("Testing feeding")
// {
//     Pet unfed_cat{ garfield };
//     garfield.feed();
//     CHECK(unfed_cat.m_happiness < garfield.m_happiness);
//     CHECK(unfed_cat.m_fullness < garfield.m_fullness);
// }

// TEST_CASE("Testing playing")
// {
//     Pet bored_dog{ oscar };
//     oscar.play();
//     CHECK(bored_dog.m_happiness < oscar.m_happiness);
//     CHECK(bored_dog.m_energy > oscar.m_energy);
// }

// TEST_CASE("Testing sleeping")
// {
//     Pet sleepy_cat{ garfield };
//     Pet sleepy_dog{ oscar };
//     garfield.sleep();
//     CHECK(sleepy_cat.m_energy < garfield.m_energy);
//     CHECK(sleepy_dog.m_energy < oscar.m_energy);
// }

// TEST_CASE("Testing saving and loading")
// {
//     save_pet_to_file(garfield);
//     save_pet_to_file(oscar);

//     Pet loaded_cat{ load_pet_from_file("Garfield") };
//     Pet loaded_dog{ load_pet_from_file("Oscar") };

//     CHECK(garfield.m_type == loaded_cat.m_type);
//     CHECK(garfield.m_name == loaded_cat.m_name);
//     CHECK(garfield.m_happiness == loaded_cat.m_happiness);
//     CHECK(garfield.m_fullness == loaded_cat.m_fullness);
//     CHECK(garfield.m_energy == loaded_cat.m_energy);

//     CHECK(oscar.m_type == loaded_dog.m_type);
//     CHECK(oscar.m_name == loaded_dog.m_name);
//     CHECK(oscar.m_happiness == loaded_dog.m_happiness);
//     CHECK(oscar.m_fullness == loaded_dog.m_fullness);
//     CHECK(oscar.m_energy == loaded_dog.m_energy);
// }
