#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void basic_test(void) {
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Test : 01" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Animal a;
		Animal b = Animal("fish");
		Animal c(b);
		Animal d;
		d = a;
		b.makeSound();
	}
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Test : 02" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Dog a;
		Dog b = Dog("Dog");
		Dog c(b);
		Dog d;
		d = a;
		b.makeSound();
	}
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Test : 03" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Cat a;
		Cat b = Cat("Cat");
		Cat c(b);
		Cat d;
		d = a;
		b.makeSound();
	}
}

void subject_tests(void) {
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Test : 06" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

int main(void) {
	basic_test();
	subject_tests();
	return (0);
}
