#include "Zombie.hpp"
#include <new>

Zombie *newZombie(const std::string& name)
{
	return (new (std::nothrow) Zombie(name));
}