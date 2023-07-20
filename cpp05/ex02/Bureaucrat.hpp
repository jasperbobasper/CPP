#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat &operator=(Bureaucrat const &rhs);
		void signForm(Form& form);
		const std::string getName(void) const;
		int getGrade(void) const;
		void incGrade(void);
		void decGrade(void);
		void executeForm(Form const &form);
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
std::ostream    &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
