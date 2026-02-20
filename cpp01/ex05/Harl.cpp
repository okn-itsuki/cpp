#include "Harl.hpp"

Harl::Harl()
{
	this->category[0] = &Harl::debug;
	this->category[1] = &Harl::info;
	this->category[2] = &Harl::warning;
	this->category[3] = &Harl::error;
}

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
			  << "I think I deserve to have some extra bacon for free."
			  << " I’ve been coming for years,"
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

	switch (level)
	{
	case 0:
		harl.debug();
	case 1:
		harl.info();
	case 2:
		harl.warning();
	case 3:
		harl.error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
	}
	return;
}