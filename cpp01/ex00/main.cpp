#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "=== heap ===" << std::endl;

	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl;
	std::cout << "=== stack ===" << std::endl;

	randomChump("StackZombie");

	return 0;
}
