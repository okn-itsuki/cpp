#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
	int N;
	std::cout << "\x1b[38;2;160;160;160m" << "N = ?" << "\x1b[m" << std::endl;
	std::cin >> N;
	if (!std::cin)
	{
		std::cerr << "\x1b[38;2;160;160;160m" << "aborted due to input error" << "\x1b[m" <<  std::endl;
		return 1;
	}

	Zombie *horde = zombieHorde(N, "iotsuki");

	if (!horde)
	{
		std::cerr << "\x1b[38;2;160;160;160m" << "Failed to create zombie horde" << "\x1b[m" << std::endl;
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
