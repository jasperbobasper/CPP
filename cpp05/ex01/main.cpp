#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Stan = Bureaucrat("Stan", 149);
	Bureaucrat Greg = Bureaucrat("Greg", 1);

	std::cout << Stan << std::endl;
	std::cout << Greg << std::endl;

	Form egg = Form("Buy egg", 150, 1);
	Form cry = Form("Crying break", 1, 150);

	std::cout << egg << std::endl;
	std::cout << cry << std::endl;

	Stan.signForm(cry);
	Stan.signForm(egg);
	Greg.signForm(cry);

	std::cout << egg << std::endl;
	std::cout << cry << std::endl;
}