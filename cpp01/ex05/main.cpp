#include "Harl.hpp"

int main()
{
	Harl instans = Harl();

	instans.complain("");
	instans.complain("DEBUG");
	instans.complain("INFO");
	instans.complain("WARNING");
	instans.complain("ERROR");

	return (0);
}
