#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name_("") {}

Zombie::~Zombie()
{
	std::cout << name_ << ": destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
	name_ = name;
}
