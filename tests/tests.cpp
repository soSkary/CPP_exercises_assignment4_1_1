#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "pet.h"


Pet garfield("Cat", "Garfield");
Pet oscar("Dog", "Oscar");

TEST_CASE("Testing pet creation")
{
    CHECK(garfield.m_type == "Cat");
    CHECK(garfield.m_name == "Garfield");
    CHECK(oscar.m_type == "Dog");
    CHECK(oscar.m_name == "Oscar");
    
}

TEST_CASE("Testing feeding")
{
    Pet unfed_cat{ garfield };
    garfield.feed();

    SUBCASE("Happiness increased from feeding")
    {
        CHECK(unfed_cat.m_happiness < garfield.m_happiness);
        //reset values, for next SUBCASE
        garfield.m_happiness = Status::neutral;
        garfield.m_fullness = Status::neutral;
    }
    SUBCASE("Fullness increased from feeding")
    {
        CHECK(unfed_cat.m_fullness < garfield.m_fullness);
    }
}

TEST_CASE("Testing playing")
{
    Pet bored_dog{ oscar };
    oscar.play();
    SUBCASE("Happiness increased from playing")
    {
        CHECK(bored_dog.m_happiness < oscar.m_happiness);
        //reset values, for next SUBCASE
        oscar.m_happiness = Status::neutral;
        oscar.m_energy = Status::neutral;
    }
    SUBCASE("Energy decreased from playing")
    {
        CHECK(bored_dog.m_energy > oscar.m_energy);
    }
}

// TEST_CASE("Testing sleeping")
// {
//     Pet sleepy_cat{ garfield };
//     Pet sleepy_dog{ oscar };
//     garfield.sleep();
//     SUBCASE("Energy increased from sleeping")
//     {
//         CHECK(sleepy_cat.m_energy < garfield.m_energy);
//         CHECK(sleepy_dog.m_energy < oscar.m_energy);
//     }
// }

// TEST_CASE("Testing saving and loading")
// {
//     save_pet_to_file(garfield);
//     save_pet_to_file(oscar);

//     Pet loaded_cat{ load_pet_from_file("Garfield") };
//     Pet loaded_dog{ load_pet_from_file("Oscar") };

//     SUBCASE("Garfield save and load function working as intended")
//     {
//         CHECK(garfield.m_type == loaded_cat.m_type);
//         CHECK(garfield.m_name == loaded_cat.m_name);
//         CHECK(garfield.m_happiness == loaded_cat.m_happiness);
//         CHECK(garfield.m_fullness == loaded_cat.m_fullness);
//         CHECK(garfield.m_energy == loaded_cat.m_energy);
//     }
//     SUBCASE("Oscar save and laod functions working as intended")
//     {
//         CHECK(oscar.m_type == loaded_dog.m_type);
//         CHECK(oscar.m_name == loaded_dog.m_name);
//         CHECK(oscar.m_happiness == loaded_dog.m_happiness);
//         CHECK(oscar.m_fullness == loaded_dog.m_fullness);
//         CHECK(oscar.m_energy == loaded_dog.m_energy);    
//     }
// }
