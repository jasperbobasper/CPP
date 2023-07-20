#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
	private:
		Form *makePPForm(std::string target);
		Form *makeRRForm(std::string target);
		Form *makeSCForm(std::string target);
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern &operator=(Intern const &rhs);
		typedef Form* (Intern::*FuncPtr)(const std::string);
		Form* makeForm(std::string name, std::string target);
};

#endif
