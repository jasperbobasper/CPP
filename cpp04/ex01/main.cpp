#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* group[10];
	std::cout << "Array test:" << std::endl;
	for (int i = 0; i < 5; i++)
		group[i] = new Cat();
	for (int i = 5; i < 10; i++)
		group[i] = new Dog();
	for (int i = 0; i < 10; i++)
		group[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete group[i];

	std::cout << "\n\nCopy test:" << std::endl;

	Cat cat;
	cat.setIdeas("meow, this is a cat thought");
	Cat tmp(cat);
	std::cout << cat.getIdeas()[2] << std::endl;
	std::cout << tmp.getIdeas()[2] << std::endl;
	tmp.setIdeas("woo");
	std::cout << cat.getIdeas()[2] << std::endl;
	std::cout << tmp.getIdeas()[2] << std::endl;
	return 0;
}