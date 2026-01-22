#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;
	bool is_set_;

public:
	Contact();

	void Set(const std::string &first,
			 const std::string &last,
			 const std::string &nick,
			 const std::string &phone,
			 const std::string &secret);

	bool IsSet() const;

	const std::string &FirstName() const;
	const std::string &LastName() const;
	const std::string &Nickname() const;
	const std::string &PhoneNumber() const;
	const std::string &DarkestSecret() const;
};

#endif