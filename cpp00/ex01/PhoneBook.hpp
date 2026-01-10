class PhoneBook
{
private:
	Contact contacts_[8];
	int next_index_;
	int stored_count_;

	static std::string ReadNonEmptyLine(const std::string& prompt);
	static std::string Truncate10(const std::string& s);

public:
	PhoneBook();

	void Add();
	void Search();
};