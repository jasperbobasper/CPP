#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Cat BobCat = Cat();
	const Dog Doge;
	//const AAnimal animal;

	BobCat.makeSound();
	Doge.makeSound();
}