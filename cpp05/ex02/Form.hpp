#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(std::string const name, int const gradeToSign, int const gradeToExec, std::string target);
		Form(Form const &src);
		~Form(void);
	protected:
		std::string const _name;
		std::string _target;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExec;
	public:
		void beSigned(Bureaucrat& someGuy);
		Form &operator=(Form const &rhs);
		std::string getName(void) const;
		std::string getTarget(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		bool getIsSigned(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		class UnsignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
std::ostream    &operator<<(std::ostream &o, Form const &rhs);
#endif
