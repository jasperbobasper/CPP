#include "Harl.hpp"

Harl::Harl(void)
{

};

Harl::~Harl(void)
{

};

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void	Harl::pass_complaint(std::string level, std::string type, void (Harl::*func)())
{
	if (level == type)
		(this->*func)();
}

void Harl::complain(std::string level)
{
	pass_complaint(level, "debug", &Harl::debug);
	pass_complaint(level, "info", &Harl::info);
	pass_complaint(level, "warning", &Harl::warning);
	pass_complaint(level, "error", &Harl::error);
};
