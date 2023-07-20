#include "phonebook.hpp"

int	main(void)
{
	int				i;
	class PhoneBook	book;
	std::string		command;

	i = 0;
	std::cout << "   ,==.-------.\n  (    ) ====  \\ \n  ||  | [][][] |\n,8||  | [][][] | \
	\n8 ||  | [][][] |\n8 (    ) O O O /\n'88`=='-------'\n\n*~ Welcome to the Phone Book of Dreams ~* \n" << std::endl;
	while (i == 0)
	{
		std::cout << "Please enter ADD to add a contact, SEARCH to search for a contact, or EXIT to exit\n" << std::endl;
		getline (std::cin, command);
		if (command == "EXIT" || command == "exit")
			i = 1;
		else if (command == "ADD" || command == "add")
			book.add_contact();
		else if (command == "SEARCH" || command == "search")
			book.search_contact();
		else
			std::cout << "invalid command, please try again\n" << std::endl;
	}
	return (0);
};