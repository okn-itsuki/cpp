#include "Contact.hpp"

Contact::Contact() : is_set_(false) {}

void Contact::Set(const std::string &first,
				  const std::string &last,
				  const std::string &nick,
				  const std::string &phone,
				  const std::string &secret)
{
	first_name_ = first;
	last_name_ = last;
	nickname_ = nick;
	phone_number_ = phone;
	darkest_secret_ = secret;
	is_set_ = true;
}

bool Contact::IsSet() const { return is_set_; }

const std::string &Contact::FirstName() const { return first_name_; }
const std::string &Contact::LastName() const { return last_name_; }
const std::string &Contact::Nickname() const { return nickname_; }
const std::string &Contact::PhoneNumber() const { return phone_number_; }
const std::string &Contact::DarkestSecret() const { return darkest_secret_; }
