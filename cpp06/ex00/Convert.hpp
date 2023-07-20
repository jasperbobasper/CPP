#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <string>
# include <climits>
# include <stdexcept>
# include <cstdlib>
# include <cerrno>
class	Convert
{
	public:
		Convert(void);
		Convert(char* str);
		Convert(Convert const &src);
		~Convert(void);
		Convert &operator=(Convert const &rhs);
	private:
		char *_input;
		int _type;
		char _c;
		int _i;
		float _f;
		double _d;
		void	printInt(void);
		void	printChar(void);
		void	printFloat(void);
		void	printDouble(void);
		int		findType(void);
		int		checkSpecial(void);
		void	strToConversion(void);

		static const int err = -1;
		static const int in = 0;
		static const int ch = 1;
		static const int fl = 2;
		static const int db = 3;

	public:
		void 	doConversions(void);
		void	printConversions(void);
		class ConversionException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class OverflowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
#endif
