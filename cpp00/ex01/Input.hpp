#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

class Input
{
public:
	static bool ReadLine(std::string &out);
	static bool ReadNonEmpty(const std::string &label, std::string &out);
	static bool ReadIndex(const std::string &label, int &out);
};

#endif
