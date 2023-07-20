#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
	std::cout << "Shrubbery Creation Form constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137, target)
{
	std::cout << "Shrubbery Creation Form other constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	std::cout << "Shrubbery Creation Form copy constructor" << std::endl;
	_isSigned = src.getIsSigned();
	_target = src.getTarget();
	return ;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery Creation Form deconstructor" << std::endl;
	return ;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	_isSigned = rhs.getIsSigned();
	_target = rhs.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream outfile;
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw Form::UnsignedException();
	outfile.open((this->getTarget() + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cout << "File could not be created :(" << std::endl;
		return ;
	}
	outfile << "/*            * *    \n           *    *  *\n      *  *    *     *  *\n     *     *    *  *    *\n\
 * *   *    *    *    *   *\n *     *  *    * * .#  *   *\n *   *     * #.  .# *   *\n  *     \"#.  #: #\" * *    *\n\
 *   * * \"#. ##\"       *\n   *       \"###\n             \"##\n              ##.\n              .##:\n              :###\n\
              ;###\n            ,####.\n         .######.*/";
	outfile.close();
}
