#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class	C : public Base 
{
	private:
	public:
		C(void);
		C(C const &src);
		~C(void);
		C &operator=(C const &rhs);
};
#endif
