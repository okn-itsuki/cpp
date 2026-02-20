#ifndef HAEL_HPP
#define HAEL_HPP

#include <iostream>
#include <string>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void (Harl::*category[4])(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif