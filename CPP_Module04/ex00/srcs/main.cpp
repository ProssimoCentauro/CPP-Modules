#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// ANSI color codes 🎨
#define RESET       "\033[0m"
#define GREEN       "\033[32m"
#define CYAN        "\033[36m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"
#define MAGENTA     "\033[35m"

int main()
{
	std::cout << MAGENTA << "🧪 Starting tests...\n" << RESET << std::endl;

	{
		std::cout << CYAN << "🔬 Creating animals...\n" << RESET;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << YELLOW << "\n🐶 Dog type: " << j->getType() << RESET << std::endl;
		std::cout << YELLOW << "🐱 Cat type: " << i->getType() << RESET << std::endl;

		std::cout << GREEN << "\n🔊 Cat sound: ";
		i->makeSound();
		std::cout << "🔊 Dog sound: ";
		j->makeSound();
		std::cout << "🔊 Animal sound: ";
		meta->makeSound();
		std::cout << RESET;

		std::cout << CYAN << "\n🧹 Deleting animals...\n" << RESET;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << MAGENTA << "\n🧪 Testing wrong classes...\n" << RESET;

	{
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		std::cout << YELLOW << "\n😼 WrongCat type: " << wrongCat->getType() << RESET << std::endl;

		std::cout << RED << "\n🔊 WrongCat makes sound (should be WrongAnimal's sound): ";
		wrongCat->makeSound();
		std::cout << "🔊 WrongAnimal makes sound: ";
		wrongMeta->makeSound();
		std::cout << RESET;

		std::cout << CYAN << "\n🧹 Deleting wrong animals...\n" << RESET;
		delete wrongMeta;
		delete wrongCat;
	}

	std::cout << MAGENTA << "\n✅ All tests finished.\n" << RESET;
	return 0;
}
