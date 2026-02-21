#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie()
{
	std::cout << name_ << ": destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}