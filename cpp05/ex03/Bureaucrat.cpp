#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(void) : _name("Generic Guy"), _grade(150)
{
	std::cout << "Bureaucrat Standard Constructeroni" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{ 
	std::cout << "Bureaucrat other Constructeroni" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else 
		_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
	_grade = src.getGrade();
	std::cout << "Bureaucrat copy constructor called " << std::endl;
	return ;
}
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called " << std::endl;
	return ;
}
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	_grade = rhs.getGrade();
	return *this;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " <<  form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
	return ;
}

void Bureaucrat::decGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
	return ;
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Attempted Grade is too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Attempted Grade is too Low");
}

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade(); 
	return o;
}
