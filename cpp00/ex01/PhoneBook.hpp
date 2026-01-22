#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
	Contact contacts_[8];
	int count_;
	int next_index_;

	static std::string ReadLine();
	static std::string PromptNonEmpty(const std::string &label);
	static std::string Truncate10(const std::string &s);
	static bool ParseIndex(const std::string &s, int &out);

public:
	PhoneBook();

	void Add();
	void Search();
};

#endif
