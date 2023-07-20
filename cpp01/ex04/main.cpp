#include <string>
#include <iostream>
#include <fstream>

std::string	ft_replace(std::string line, std::string s1, std::string s2, std::size_t pos)
{
	line.erase(pos, s1.size());
	line.insert(pos, s2);
	return (line);
};

int	main(int argc, char *argv[])
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "Usage: ./ex04 <filename> <string to find> <string to replace>" << std::endl;
		return (-1);
	}
	std::string filename = argv[1];
	std::ifstream ifs(filename);
	if (ifs.fail())
	{
		std::cout << "Error: File could not be opened" << std::endl;
		return (-1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	std::ofstream ofs(filename + ".replace");
	std::string file;
	std::size_t found;
	while (std::getline(ifs, file, '\n'))
	{
		found = file.find(s1);
		if (found != std::string::npos)
			ofs << ft_replace(file, s1, s2, found) << std::endl;
		else
			ofs << file << std::endl;
	}
	ifs.close();
	return (0);
}