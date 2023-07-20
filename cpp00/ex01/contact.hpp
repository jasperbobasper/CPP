#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public: 
	Contact(void);
	~Contact(void);
	void set_contact(void);
	void get_contact(void) const;
	void get_contact_con(void) const;

	private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif