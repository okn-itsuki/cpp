class Contact
{
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

	public:
	void SetFirstName(const std::string& v);
	void SetLastName(const std::string& v);
	void SetNickname(const std::string& v);
	void SetPhoneNumber(const std::string& v);
	void SetDarkestSecret(const std::string& v);

	const std::string& GetFirstName() const;
	const std::string& GetLastName() const;
	const std::string& GetNickname() const;
	const std::string& GetPhoneNumber() const;
	const std::string& GetDarkestSecret() const;

	bool IsEmpty() const;
	void Clear();
};