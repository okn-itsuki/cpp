#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		void setType(std::string newType);
		const std::string &getType() const;

	private:
		Weapon();
		std::string	type_;
};

#endif