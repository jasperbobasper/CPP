#include "Intern.hpp"
Intern::Intern(void)
{
	std::cout << "Intern constructor" << std::endl;
	return ;
}
Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = src;
	return ;
}
Intern::~Intern(void)
{
	std::cout << "Intern deconstructor" << std::endl;
	return ;
}
Intern	&Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return *this;
}

Form* Intern::makePPForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
Form* Intern::makeRRForm(std::string target)
{
	return new RobotomyRequestForm(target);
}
Form* Intern::makeSCForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	FuncPtr funcs[3] = {&Intern::makePPForm, &Intern::makeSCForm, &Intern::makeSCForm};
	std::string forms[3] = {"Presidential Pardon Form", "Shrubbery Creation Form", "Robotomy Request Form"};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Requested form could not be found" << std::endl;
	return NULL;
}