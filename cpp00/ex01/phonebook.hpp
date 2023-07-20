#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook
{
	public: 

	PhoneBook (void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search_contact(void) const;

	private:
	Contact	_contacts[8];
	int _numContacts;
};

#endif