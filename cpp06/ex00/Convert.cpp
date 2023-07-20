#include "Convert.hpp"
Convert::Convert(void)
{
	_input = NULL;
	_type = -1;
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
	return ;
}

Convert::Convert(char* str)
{
	_input = str;
	_type = -1;
	_c = 0;
	_i = 0;
	_f = 0;
	_d = 0;
}

Convert::Convert(Convert const &src)
{
	_input = src._input;
	_type = src._type;
	_c = src._c;
	_i = src._i;
	_f = src._f;
	_d = src._d;
	return ;
}

Convert::~Convert(void)
{
	return ;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	_input = rhs._input;
	_type = rhs._type;
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	return *this;
}
int	Convert::checkSpecial(void)
{
	std::string check_floats[] = 
	{
		"-inff", "+inff", "nanf"
	};
	std::string check_doubles[] = 
	{
		"-inf", "+inf", "nan"
	};
	for (int i = 0; i < 3; i++)
	{
		if (check_floats[i] == this->_input)
			return (Convert::fl);
		if (check_doubles[i] == this->_input)
			return (Convert::db);	
	}
	return (Convert::in);
}

int	Convert::findType(void)
{
	if (strlen(this->_input) == 1)
	{
		if (std::isdigit(this->_input[0]) != 0)
			return (Convert::in);
		else 
			return (Convert::ch);
	}
	int i = checkSpecial();
	if (i != 0)
		return (i);
	else
	{
		if (strchr(this->_input, '.') == NULL)
			return(Convert::in);
		if (strchr(this->_input, 'f') == NULL)
			return(Convert::db);
		else
			return(Convert::fl);
	}
	return(Convert::err);
}

void	Convert::strToConversion(void)
{
	if (_type == -1)
		throw Convert::ConversionException();
	errno = 0;
	long int tmp = strtol(_input, NULL, 10);
	tmp++;
	if (errno != 0)
		throw Convert::OverflowException();
	if (_type == 0)
	{
		if (sscanf(_input, "%d", &this->_i) != 1)
			throw Convert::ConversionException();
	}
	if (_type == 1)
		_c = _input[0];
	if (_type == 2)
	{
		if (sscanf(_input, "%f", &this->_f) != 1)
			throw Convert::ConversionException();
	}
	if (_type == 3)
	{
		if (sscanf(_input, "%lf", &this->_d) != 1)
			throw Convert::ConversionException();
	}
}

void Convert::doConversions(void)
{
	_type = this->findType();
	strToConversion();
	if (_type == -1)
	{
		std::cerr << "type has not been set";
		return ;
	}
	if (_type == Convert::in)
	{
		_f = static_cast<float>(_i);
		_d = static_cast<double>(_i);
		_c = static_cast<char>(_i);
	}
	if (_type == Convert::ch)
	{
		_f = static_cast<float>(_c);
		_d = static_cast<double>(_c);
		_i = static_cast<int>(_c);
	}
	if (_type == Convert::fl)
	{
		_i = static_cast<int>(_f);
		_d = static_cast<double>(_f);
		_c = static_cast<char>(_f);
	}
	if (_type == Convert::db)
	{
		_f = static_cast<float>(_d);
		_i = static_cast<int>(_d);
		_c = static_cast<char>(_d);
	}
}

void	Convert::printConversions(void)
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Convert::printInt(void)
{
	if (_f <= INT_MAX && _f >= INT_MIN)
		std::cout << "int: " << _i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	Convert::printChar(void)
{
	if (_c > 32 && _c < 127)
		std::cout << "char: " << _c << std::endl;
	else if (isascii(_i) > 0)
		std::cout << "char: non displayable" << std::endl;
	else 
		std::cout << "char: impossible" << std::endl;
}

void	Convert::printFloat(void)
{
	std::cout << "float: " << _f;
	if (abs(floor(_f)) == _f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}
void	Convert::printDouble(void)
{
	std::cout << "double: " << _d;
	if (abs(floor(_d)) == _d)
		std::cout << ".0";
	std::cout << std::endl;
}

const char * Convert::ConversionException::what() const throw()
{
	return("Type Cannot be converted");
}

const char * Convert::OverflowException::what() const throw()
{
	return("Value overflow");
}