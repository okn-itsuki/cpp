#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl instans = Harl();
	if (argc != 2)
	{
		std::cout
			<< "[ Invalid argment. "
			<< "please provide one of :"
			<< "\"DEBUG\",\"INFO\", \"WARNING\", \"ERROR\" ]"
			<< std::endl;
		return (1);
	}

	instans.complain(argv[1]);

	return (0);
}
