#include "Form.hpp"

Form::Form(void) : _name("Generic Form"), _target("target"), _isSigned(false), _gradeToSign(150),  _gradeToExec(1)
{
	std::cout << "standard form constructor" << std::endl;
	return ;
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExec, std::string target) 
: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "form constructor" << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	_isSigned = src.getIsSigned();
	return ;
}
Form::~Form(void)
{
	std::cout << "form deconstructor" << std::endl;
	return ;
}
Form	&Form::operator=(Form const &rhs)
{
	_isSigned = rhs.getIsSigned();
	return *this;
}

void Form::beSigned(Bureaucrat &someGuy)
{
	if (someGuy.getGrade() > this->getGradeToSign())
	{
		throw Form::GradeTooLowException();
		return ;
	}
	_isSigned = true;
}

std::string Form::getName(void) const
{
	return _name;
}
int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}
int Form::getGradeToExec(void) const
{
	return _gradeToExec;
}
bool Form::getIsSigned(void) const
{
	return _isSigned;
}

std::string Form::getTarget(void) const
{
	return _target;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return("Attempted Grade is too High for the form");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return("Attempted Grade is too Low for the form");
}

const char * Form::UnsignedException::what() const throw()
{
	return("Form has not been signed");
}

std::ostream    &operator<<(std::ostream &o, Form const &rhs)
{
	std::cout << rhs.getName() << ": grade to sign= " << rhs.getGradeToSign() << ", grade to execute= " << rhs.getGradeToExec() << ", is signed? ";
	if (rhs.getIsSigned() == true)
		std::cout << "yes";
	else 
		std::cout << "no";
	return o;
}

