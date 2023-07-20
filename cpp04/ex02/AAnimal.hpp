#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"
class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);
		AAnimal &operator=(AAnimal const &rhs);
	protected:
		std::string _type;
	public:
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};
#endif
