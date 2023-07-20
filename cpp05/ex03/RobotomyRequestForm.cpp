#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
	std::cout << "Robotomy Request Form constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45, target)
{
	std::cout << "Robotomy Request Form other constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src)
{
	std::cout << "Robotomy Request Form copy constructor" << std::endl;
	_isSigned = src.getIsSigned();
	_target = src.getTarget();
	return ;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy Request Form deconstructor" << std::endl;
	return ;
}
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	_isSigned = rhs.getIsSigned();
	_target = rhs.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw Form::UnsignedException();
	std::cout << "*Bzzzzzzzzttt* ";
	if (std::rand() % 2 == 1)
		std::cout << "Robotomy on " << this->getTarget() << " was successful!" << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed!" << std::endl;
	return ;
}