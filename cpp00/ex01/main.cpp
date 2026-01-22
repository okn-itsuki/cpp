#include "PhoneBook.hpp"
#include "Input.hpp"
#include <iostream>
#include <iomanip>

static std::string ReadLine();

int main()
{
	PhoneBook phonebook;

	while (true)
	{
		try
		{
			std::cout << "Enter command (ADD, SEARCH, EXIT): ";
			std::string command = ReadLine();

			if (!std::cin) // EOF or input error
				break;

			if (command == "ADD")
				phonebook.Add();
			else if (command == "SEARCH")
				phonebook.Search();
			else if (command == "EXIT")
				break;
			else if (command.empty())
				std::cout << "Unknown command.\n";
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
	}
	return 0;
}

static std::string ReadLine()
{
	std::string line;
	if (!std::getline(std::cin, line))
		return std::string();
	return line;
}
