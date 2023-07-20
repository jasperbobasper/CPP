#include <iostream>

int	main(int argc, char *argv[])
{
	std::string input;

	for (int i = 1; i < argc; i++)
	{
		input += argv[i];
	}
	if (input == "")
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for(long unsigned int i = 0; i < input.length(); i++)
		{
			input[i] = toupper(input[i]);
		}
		std::cout << input << std::endl;
	}
	return (0);
}