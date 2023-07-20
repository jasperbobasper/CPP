#include "dataStruct.hpp"
#include <stdint.h>

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data 	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	Data	*data = new Data;
	Data	*ptr;
	uintptr_t raw;

	data->data = "test test wow data";
	raw = serialize(data);
	std::cout << raw << std::endl;
	ptr = deserialize(raw);
	std::cout << ptr->data << std::endl;
	delete data;
}