#include "Harl.hpp"

Harl::Harl()
{
	this->category[0] = &Harl::debug;
	this->category[1] = &Harl::info;
	this->category[2] = &Harl::warning;
	this->category[3] = &Harl::error;
}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "\x1b[35mDEBUG\x1b[m : "
			  << "I love having extra bacon "
			  << "for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
			  << "I really do!"
			  << std::endl;
	return;
}

void Harl::info(void)
{
	std::cout << "\x1b[34mINFO\x1b[m : "
			  << "I cannot believe adding extra bacon costs more money."
			  << "You didn’t put enough bacon in my burger!"
			  << " If you did, I wouldn’t be asking for more!"
			  << std::endl;
	return;
}

void Harl::warning(void)
{
	std::cout << "\x1b[33mWRNG\x1b[m : "
			  << "I think I deserve to have some extra bacon"
			  << " for free. I’ve been coming for years,"
			  << " whereas you started working here just last month."
			  << std::endl;
	return;
}

void Harl::error(void)
{
	std::cout << "\x1b[31mERR\x1b[m : "
			  << "This is unacceptable!"
			  << "I want to speak to the manager now."
			  << std::endl;
	return;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			(this->*category[i])();
	}
	return;
}