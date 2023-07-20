#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class	A : public Base
{
	private:
	public:
		A(void);
		A(A const &src);
		~A(void);
		A &operator=(A const &rhs);
};
#endif
