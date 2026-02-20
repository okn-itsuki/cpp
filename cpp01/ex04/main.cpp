#include <iostream>
#include <string>
#include <fstream>

bool replaceFile(std::string file, std::string s1, std::string s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty\n";
		return false;
	}

	std::ifstream ifs(file.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open input file\n";
		return false;
	}

	std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	std::string result;
	result.reserve(content.size());

	std::size_t pos = 0;
	while (true)
	{
		std::size_t idx = content.find(s1, pos);
		if (idx == std::string::npos)
		{
			result.append(content, pos, std::string::npos);
			break;
		}
		result.append(content, pos, idx - pos);
		result.append(s2);
		pos = idx + s1.size();
	}

	std::ofstream ofs((file + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: cannot open output file\n";
		return false;
	}
	ofs << result;
	ofs.close();

	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Using: ./replace <file> <s1> <s2>" << std::endl;
		return (1);
	}

	const std::string file = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	if (!replaceFile(file, s1, s2))
		return 1;

	return (0);
}
