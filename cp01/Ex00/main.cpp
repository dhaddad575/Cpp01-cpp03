#include "zombie.hpp"
#include <iostream>

Zombie *NewZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    Zombie *zombie1 = NewZombie("Zombie1");
    zombie1->announce();
    delete zombie1;

    randomChump("Zombie2");

    return 0;
}