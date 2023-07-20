#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>
# include <string>
# include <fstream>
class	ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);
		void execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
};
#endif
