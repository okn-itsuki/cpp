#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

PhoneBook::PhoneBook() : count_(0), next_index_(0) {}

std::string PhoneBook::ReadLine()
{
	std::string line;
	if (!std::getline(std::cin, line))
		return std::string();
	return line;
}

std::string PhoneBook::PromptNonEmpty(const std::string &label)
{
	while (true)
	{
		std::cout << label;
		std::string s = ReadLine();

		if (!std::cin) // EOF
			throw std::runtime_error("input terminated (EOF)");

		if (!s.empty())
			return s;

		std::cout << "Input cannot be empty.\n";
	}
}

std::string PhoneBook::Truncate10(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

bool PhoneBook::ParseIndex(const std::string &s, int &out)
{
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}

	long v = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		v = v * 10 + (s[i] - '0');
		if (v > 1000000) // 雑な上限でオーバーフロー回避
			return false;
	}

	out = static_cast<int>(v);
	return true;
}

void PhoneBook::Add()
{
	std::string fn = PromptNonEmpty("First name: ");
	std::string ln = PromptNonEmpty("Last name: ");
	std::string nn = PromptNonEmpty("Nickname: ");
	std::string pn = PromptNonEmpty("Phone number: ");
	std::string ds = PromptNonEmpty("Darkest secret: ");

	contacts_[next_index_].Set(fn, ln, nn, pn, ds);

	next_index_ = (next_index_ + 1) % 8;
	if (count_ < 8)
		count_++;

	std::cout << "Saved.\n";
}

void PhoneBook::Search()
{
	if (count_ == 0)
	{
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "\n";

	for (int i = 0; i < count_; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << Truncate10(contacts_[i].FirstName()) << "|"
				  << std::setw(10) << Truncate10(contacts_[i].LastName()) << "|"
				  << std::setw(10) << Truncate10(contacts_[i].Nickname())
				  << "\n";
	}

	std::cout << "Index to display: ";
	std::string s = ReadLine();
	if (!std::cin)
		throw std::runtime_error("input terminated (EOF)");

	int idx;
	if (!ParseIndex(s, idx) || idx < 0 || idx >= count_)
	{
		std::cout << "Invalid index.\n";
		return;
	}

	std::cout << "First name: " << contacts_[idx].FirstName() << "\n";
	std::cout << "Last name: " << contacts_[idx].LastName() << "\n";
	std::cout << "Nickname: " << contacts_[idx].Nickname() << "\n";
	std::cout << "Phone number: " << contacts_[idx].PhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contacts_[idx].DarkestSecret() << "\n";
}
