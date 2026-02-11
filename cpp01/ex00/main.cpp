#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "\x1b[38;2;160;160;160m" << "=== heap ===" << "\x1b[m" << std::endl;

	Zombie *heapZombie = newZombie("HeapZombie");
	if (heapZombie == NULL)
		return 1;
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl;
	std::cout << "\x1b[38;2;160;160;160m" << "=== stack ===" << "\x1b[m" << std::endl;

	randomChump("StackZombie");

	return 0;
}
