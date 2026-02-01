#include <iostream>

int main(void)
{
	std::string reference = "HI THIS IS BRAIN";
	std::string *stringPTR = &reference;
	std::string &stringREF = reference;

	std::cout << "Addresses" << std::endl;
	// • The memory address of the string variable.
	// • The memory address held by stringPTR.
	// • The memory address held by stringREF.
	std::cout << &reference << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "Value" << std::endl;
	// • The value of the string variable.
	// • The value pointed to by stringPTR.
	// • The value pointed to by stringRE
	std::cout << reference << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}