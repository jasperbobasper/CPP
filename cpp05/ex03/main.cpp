#include "Intern.hpp"

int main(void)
{
	Bureaucrat Stan = Bureaucrat("Stan", 1);
	Intern someGuy;
	Form *pp;
	Form *scf;
	
	pp = someGuy.makeForm("Presidential Pardon Form", "My Mum");
	scf = someGuy.makeForm("Shrubbery Creation Form", "Backyard");
	Stan.signForm(*pp);
	Stan.executeForm(*pp);
	Stan.signForm(*scf);
	Stan.executeForm(*scf);
	delete pp;
	delete scf;
}