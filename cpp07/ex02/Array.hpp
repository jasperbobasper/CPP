#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template < typename T > 
class Array
{
	public:
		Array< T >( void ) : _array(new T[0]), _size(0)
		{
			std::cout << "blank template constructor" << std::endl;
		}
		Array< T >( int n ) : _array(new T[n]), _size(n)
		{
			std::cout << "size template constructor" << std::endl;
		}
		Array< T >( const Array<T> &src )
		{
			_size = src._size;
			if (_size > 0)
				_array = new T[_size];
			else 
				_array = new T[0];
			for (int i = 0; i < _size; i++)
				_array[i] = src._array[i];
			std::cout << "template copy constructor" << std::endl;
		}
		~Array< T >( void )
		{
			delete [] _array;
			std::cout << "template destructor" << std::endl;
		}
		Array< T >	&operator=( const Array<T> &rhs )
		{
			_size = rhs._size;
			if (_size > 0)
				_array = new T[_size];
			else 
				_array = new T[0];
			for (int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return *this;
		}
	private:
		T *_array;
		int _size;
	public:
		int size(void)
		{
			return this->_size;
		};
		class OOBException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Index is out of bounds");
				}
		};
		T	&operator[](const int idx)
		{
			if (idx > _size || idx < 0)
				throw Array::OOBException();
			else
				return(this->_array[idx]);
		}

		const T	&operator[](const int idx) const
		{
			if (idx > _size || idx < 0)
				throw Array::OOBException();
			else
				return(this->_array[idx]);
		}
};

#endif