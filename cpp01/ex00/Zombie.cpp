#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	Zombie::name_ = name;
}

Zombie::~Zombie()
{
	std::cout << name_ << ": destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}