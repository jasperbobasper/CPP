#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Stan = Bureaucrat("Stan", 149);
	Bureaucrat Greg = Bureaucrat("Greg", 1);

	std::cout << Stan << std::endl;
	std::cout << Greg << std::endl;

	try
	{
		Stan.decGrade();
		Greg.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << Stan << std::endl;
	std::cout << Greg << std::endl;

	try
	{
		Greg.decGrade();
		Stan.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << Stan << std::endl;
	std::cout << Greg << std::endl;
}