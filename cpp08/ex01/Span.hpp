#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
class	Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);
	private:
		unsigned int _N;
		std::vector<int> _vct;
	public:
		void addNumber( int i );
		int	shortestSpan( void );
		int longestSpan( void ) const;
		void fillRand(void);
		void printContents(void);
		class TooManyElementsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
#endif
