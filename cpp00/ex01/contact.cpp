#include "contact.hpp"

Contact::Contact(void) 
{

};

Contact::~Contact(void) 
{
	
};

std::string get_input(std::string input)
{
	std::string temp;

	std::cout << input;
	getline (std::cin, temp);
	while (temp == "")
	{
		std::cout << "Line may not remain empty\n" << input;
		getline (std::cin, temp);
	}
	return (temp);
};

void	Contact::set_contact(void)
{
	std::cout << "Please enter the following information\n" << std::endl;
	_firstName = get_input("FIRST NAME: ");
	_lastName = get_input("LAST NAME: ");
	_nickName = get_input("NICKNAME: ");
	_phoneNumber = get_input("PHONE NUMBER: ");
	_darkestSecret = get_input("DARKEST SECRET: ");
};

void	Contact::get_contact(void) const
{
	std::cout << "FIRST NAME: " << _firstName << std::endl;
	std::cout << "LAST NAME: " << _lastName << std::endl;
	std::cout << "NICKNAME: " << _nickName << std::endl;
	std::cout << "PHONE NUMBER: " << _phoneNumber << std::endl;
	std::cout << "DARKEST SECRET: " << _darkestSecret << std::endl;
};

void	Contact::get_contact_con(void) const
{
	if (_firstName.length() > 10)
		std::cout << "|" << _firstName.substr(0, 9) << ".|";
	else 
		std::cout << "|" << std::setw(10) << _firstName << "|";
	if (_lastName.length() > 10)
		std::cout << _lastName.substr(0, 9) << ".|";
	else 
		std::cout << std::setw(10) << _lastName << "|";
	if (_nickName.length() > 10)
		std::cout << _nickName.substr(0, 9) << ".|" << std::endl;
	else 
		std::cout << std::setw(10) << _nickName << "|" << std::endl;
};
