#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"
class	Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal &operator=(Animal const &rhs);
	protected:
		std::string _type;
	public:
		virtual void makeSound(void) const;
		std::string getType(void) const;
};
#endif
