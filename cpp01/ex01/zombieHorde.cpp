#include "Zombie.hpp"

/// It must allocate N Zombie objects in a single allocation.
/// Then, it must initialize the
/// zombies, giving each of them the name passed as a parameter.
/// The function returns a pointer to the first zombie.
Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].SetName(name);
	return horde;
}
