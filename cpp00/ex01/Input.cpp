#include "Input.hpp"
#include <iostream>

bool Input::ReadLine(std::string &out)
{
	out.clear();
	if (!std::getline(std::cin, out))
		return false; // EOF or error
	return true;
}

bool Input::ReadNonEmpty(const std::string &label, std::string &out)
{
	while (true)
	{
		std::cout << label;
		if (!ReadLine(out))
			return false;

		if (!out.empty())
			return true;

		std::cout << "Input cannot be empty.\n";
	}
}

bool Input::ReadIndex(const std::string &label, int &out)
{
	std::string s;

	std::cout << label;
	if (!ReadLine(s))
		return false;

	if (s.empty())
		return false;

	long v = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
		v = v * 10 + (s[i] - '0');
	}

	out = static_cast<int>(v);
	return true;
}
