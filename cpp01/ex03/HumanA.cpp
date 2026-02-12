#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon) {}

void HumanA::attack() const
{
	std::cout << _name << "\x1b[38;2;120;120;120m" << " attacks with their " << "\x1b[m" << _weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &newWeapon)
{
	_weapon = newWeapon;
}