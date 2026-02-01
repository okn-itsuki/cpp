#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string name_;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void SetName(std::string naem);
};

Zombie *zombieHorde(int N, std::string name);

#endif