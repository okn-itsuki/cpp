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
	std::cout << "[ DEBUG ]\n "
			  << "I love having extra bacon "
			  << "for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
			  << "I really do!\n"
			  << std::endl;
	return;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money."
			  << "You didn’t put enough bacon in my burger!"
			  << " If you did, I wouldn’t be asking for more!\n"
			  << std::endl;
	return;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years, "
			  << "whereas you started working here just last month.\n"
			  << std::endl;
	return;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable!"
			  << "I want to speak to the manager now.\n"
			  << std::endl;
	return;
}

Harl::Level Harl::toLevel(std::string level)
{
	if (level == "DEBUG")
		return DEBUG;
	if (level == "INFO")
		return INFO;
	if (level == "WARNING")
		return WARNING;
	if (level == "ERROR")
		return ERROR;
	return INVALID;
}

void Harl::complain(std::string level)
{
	Level lv = toLevel(level);

	switch (lv)
	{
	case DEBUG:
		debug();
		info();
		warning();
		error();
		break;
	case INFO:
		info();
		warning();
		error();
		break;
	case WARNING:
		warning();
		error();
		break;
	case ERROR:
		error();
		break;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
	}
	return;
}
