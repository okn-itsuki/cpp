#include <iostream>
#include <cctype>

#define ERROR_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

class Megaphon
{
	private :

	Megaphon();

	static bool	has_non_empty_args(int argc, char **argv)
	{
		for (int i = 1; i < argc; ++i)
		{
			if (argv[i][0] != '\0')
			{
				return true;
			}
		}
		return false;
	}

	public :

	static void	validata_args_or_throw(int argc, char **argv)
	{
		if (argc < 2)
		{
			throw ERROR_MESSAGE;
		}
		if (!has_non_empty_args(argc,argv))
		{
			throw ERROR_MESSAGE;
		}
	}

	static void	print_uppercase(int argc, char **argv)
	{
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j]; ++j)
			{

				unsigned char ch = static_cast<unsigned char>(argv[i][j]);
				std::cout << static_cast<char>(std::toupper(ch));
			}
		}
		std::cout << std::endl;
	}
};

int main(int argc, char **argv)
{
	try
	{
		Megaphon::validata_args_or_throw(argc,argv);
		Megaphon::print_uppercase(argc,argv);
	}
	catch (const char *message)
	{
		std::cerr << message << std::endl;
		return 1;
	}
	return 0;
}