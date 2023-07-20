#include "phonebook.hpp"

PhoneBook::PhoneBook (void)
{
	_numContacts = 0;
};

PhoneBook::~PhoneBook (void)
{

};

int toint(std::string string)
{
	int	i;

	i = 0;
	if (string == "")
		return (-1);
	if (string.length() > 1)
		return (-1);
	if (string[0] < '0' || string[0] > '9')
		return (-1);
	std::stringstream degree(string);
    degree >> i;
	return (i);
};

void	PhoneBook::add_contact(void)
{
	int i;

	_numContacts++;
	i = _numContacts;
	if (_numContacts > 8)
		i = _numContacts % 8;
	_contacts[i - 1].set_contact();
	std::cout << "Contact saved!\n\n";
};

void	PhoneBook::search_contact(void) const
{
	int	i;
	int	idx;
	std::string input;

	i = 0;
	if (_numContacts == 0)
	{
		std::cout << "Phone Book empty :( get some friends, loser!\n" << std::endl;
		return ;
	}
	std::cout << "\nINDEX     |FIRST NAME|LAST NAME |NICKNAME  |\n";
	while (i < _numContacts && i < 8)
	{
		std::cout << i + 1 << "         ";
		_contacts[i].get_contact_con();
		i++;
	}
	std::cout << "\nPlease enter the index of the contact you would like to search: " << std::endl;
	getline(std::cin, input);
	idx = toint(input);
	while (idx < 1 || idx > _numContacts || idx > 8)
	{
		std::cout << "\nInvalid input, please input a valid idx: " << std::endl;
		getline(std::cin, input);
		idx = toint(input);
	}
	_contacts[idx - 1].get_contact();
};