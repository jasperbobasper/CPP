#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
	std::cout << "Presidential Pardon Form constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5, target)
{
	std::cout << "Presidential Pardon Form other constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src)
{
	std::cout << "Presidential Pardon Form copy constructor" << std::endl;
	_isSigned = src.getIsSigned();
	_target = src.getTarget();
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon Form deconstructor" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	_isSigned = rhs.getIsSigned();
	_target = rhs.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw Form::UnsignedException();
	std::cout << this->getTarget() << " has been pardoned by Intergalactic President Zaphod Beeblebrox" << std::endl;
}