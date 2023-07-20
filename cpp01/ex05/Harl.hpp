#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
	private:
		void	pass_complaint(std::string level, std::string type, void (Harl::*func)());
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

# endif