#include "ClapTrap.hpp"

#include <iostream>

int main()
{
    std::cout << "--- Acciones normales ---" << std::endl;
    ClapTrap bob("Bob");
    bob.attack("Alice");
    bob.takeDamage(4);
    bob.beRepaired(3);

    std::cout << "--- Energia Agotada ---" << std::endl;
    ClapTrap tired("Tired");
    for (int i =  0; i < 11; ++i)
        tired.attack("Target");
    tired.attack("Target");
    tired.beRepaired(1);

    std::cout << "--- Sin Hit Points ---" << std::endl;
    ClapTrap broken("Broken");
    broken.takeDamage(50);
    broken.attack("Una Pared");
    broken.beRepaired(1);

    std::cout << "--- Copia y Asignacion ---" << std::endl;
    ClapTrap copy(bob);
    ClapTrap assigned;
    assigned = copy;
    assigned.attack("Copy Target");

    return 0;
}