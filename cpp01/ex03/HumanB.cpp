#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL) {}

void HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << "\x1b[38;2;120;120;120m" << " has nosing weapon." << "\x1b[m" << std::endl;
	else
		std::cout << _name << "\x1b[38;2;120;120;120m" << " attacks with their " << "\x1b[m" << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	_weapon = &newWeapon;
}