#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main()
{
    std::cout << "--- ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("un objetivo");

    std::cout << "\n--- ScavTrap ---" << std::endl;
    ScavTrap scav("Serena");
    scav.attack("un objetivo");
    scav.takeDamage(15);
    scav.beRepaired(5);
    scav.guardGate();

    std::cout << "\n--- FragTrap ---" << std::endl;
    {
        FragTrap frag("Fraggy");
        frag.attack("un objetivo");
        frag.takeDamage(40);
        frag.beRepaired(10);
        frag.highFivesGuys();

        std::cout << "\n--- Copying FragTrap ---" << std::endl;
        FragTrap copy(frag);
        copy.attack("otro objetivo");
    }
    return 0;
}