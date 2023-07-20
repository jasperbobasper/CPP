#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Stan = Bureaucrat("Stan", 137);
	Bureaucrat Harry("Harry", 70);
	Bureaucrat Greg = Bureaucrat("Greg", 1);

	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robo("Myself");
	PresidentialPardonForm president("Ford Prefect");

	Stan.signForm(shrub);
	Stan.executeForm(shrub);

	Harry.signForm(robo);
	Stan.executeForm(robo);
	Harry.executeForm(robo);

	Greg.executeForm(president);
	Greg.signForm(president);
	Greg.executeForm(president);
}