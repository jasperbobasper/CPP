#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return("Int was not found");
		}
};

template < typename T >
typename T::iterator easyfind( T &intList, int i )
{
	typename T::iterator	ret = find(intList.begin(), intList.end(), i);
	if (ret == intList.end())
		throw ::NotFoundException();
	else 
		return (ret);
}

#endif