#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat  : public AAnimal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);
		Cat &operator=(Cat const &rhs);
		void makeSound(void) const;
		void setIdeas(std::string thoughts) const;
		std::string* getIdeas(void) const;
	private:
		Brain* _brain;
};
#endif
