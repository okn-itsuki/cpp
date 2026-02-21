#include <iostream>
#include <iomanip>

int main(void)
{
	std::string reference = "HI THIS IS BRAIN";
	std::string *stringPTR = &reference;
	std::string &stringREF = reference;

	std::cout << "\x1b[38;2;160;160;160m" << "Addresses :" << "\x1b[m" << std::endl;
	// • The memory address of the string variable.
	// • The memory address held by stringPTR.
	// • The memory address held by stringREF.
	std::cout << std::setw(20) << &reference << std::endl;
	std::cout << std::setw(20) << stringPTR << std::endl;
	std::cout << std::setw(20) << &stringREF << std::endl;

	std::cout << "\x1b[38;2;160;160;160m" << "Value" << "\x1b[m" << std::endl;
	// • The value of the string variable.
	// • The value pointed to by stringPTR.
	// • The value pointed to by stringRE
	std::cout << std::setw(20) << reference << std::endl;
	std::cout << std::setw(20) << *stringPTR << std::endl;
	std::cout << std::setw(20) << stringREF << std::endl;

	return 0;
}