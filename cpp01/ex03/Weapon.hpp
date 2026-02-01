#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
public:
	Weapon(std::string weapon);
	~Weapon();

	void setType(std::string club);
};

#endif