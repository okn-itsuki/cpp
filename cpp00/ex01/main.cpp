#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

static std::string ReadLine();

int main()
{
	PhoneBook pb;

	while (true)
	{
		try
		{
			std::cout << "Enter command (ADD, SEARCH, EXIT): ";
			std::string cmd = ReadLine();

			if (!std::cin) // EOF or input error
				break;

			if (cmd == "ADD")
			{
				pb.Add();
			}
			else if (cmd == "SEARCH")
			{
				pb.Search();
			}
			else if (cmd == "EXIT")
			{
				break;
			}
			else if (cmd.empty())
			{
				// 何もしない（空行は無視）
			}
			else
			{
				std::cout << "Unknown command.\n";
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		return 0;
	}
}

static std::string ReadLine()
{
	std::string line;
	if (!std::getline(std::cin, line))
		return std::string();
	return line;
}
