#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;
	if (!std::cin)
	{
		std::cerr << "aborted due to input error" << std::endl;
		return 1;
	}

	Zombie *horde = zombieHorde(N, "iotsuki");

	if (!horde)
	{
		std::cerr << "Failed to create zombie horde" << std::endl;
		return 1;
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << (i + 1) << " :";
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
