#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main()
{
    std::cout << "--- ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("un objetivo");

    std::cout << "\n--- ScavTrap ---" << std::endl;
    {
    ScavTrap scav("Serena");
    scav.attack("un objetivo");
    scav.takeDamage(15);
    scav.beRepaired(5);
    scav.guardGate();
    }

    std::cout << "\n--- ScavTrap Copy ---" << std::endl;
    ScavTrap original("Original");
    ScavTrap copia(original);
    ScavTrap asignado("Asignacion");
    asignado = original;
    asignado.attack("un objetivo");

    return 0;
}