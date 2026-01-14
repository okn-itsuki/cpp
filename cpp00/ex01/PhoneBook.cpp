#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

PhoneBook::PhoneBook() : next_index_(0), stored_count_(0)
{
}

std::string PhoneBook::ReadNonEmptyLine(const std::string &prompt)
{
    std::string line;

    std::cout << prompt;
    if (!std::getline(std::cin, line))
        throw std::runtime_error("input error");

    if (line.empty())
        throw std::runtime_error("empty field");

    return line;
}

void PhoneBook::Add()
{
    Contact c;

    c.SetFirstName(ReadNonEmptyLine("First name: "));
    c.SetLastName(ReadNonEmptyLine("Last name: "));
    c.SetNickname(ReadNonEmptyLine("Nickname: "));
    c.SetPhoneNumber(ReadNonEmptyLine("Phone number: "));
    c.SetDarkestSecret(ReadNonEmptyLine("Darkest secret: "));

    contacts_[next_index_] = c;
    next_index_ = (next_index_ + 1) % 8;
    if (stored_count_ < 8)
        stored_count_++;
}

std::string PhoneBook::Truncate10(const std::string &s)
{
    if (s.length() <= 10)
        return s;
    return s.substr(0, 9) + ".";
}

void PhoneBook::Search()
{
    if (stored_count_ == 0)
        throw std::runtime_error("phonebook is empty");

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < stored_count_; ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << Truncate10(contacts_[i].GetFirstName()) << "|"
                  << std::setw(10) << Truncate10(contacts_[i].GetLastName()) << "|"
                  << std::setw(10) << Truncate10(contacts_[i].GetNickname()) << "\n";
    }

    std::cout << "Index: ";
    std::string input;
    if (!std::getline(std::cin, input))
        throw std::runtime_error("input error");

    if (input.size() != 1 || input[0] < '0' || input[0] > '7')
        throw std::runtime_error("invalid index");

    int idx = input[0] - '0';
    if (idx >= stored_count_)
        throw std::runtime_error("index out of range");

    const Contact &c = contacts_[idx];
    std::cout << "First name: " << c.GetFirstName() << "\n";
    std::cout << "Last name: " << c.GetLastName() << "\n";
    std::cout << "Nickname: " << c.GetNickname() << "\n";
    std::cout << "Phone number: " << c.GetPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << c.GetDarkestSecret() << "\n";
}
