/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:10:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;

	std::cout << "\n----WrongAnimal----" <<std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrongmeta->getType() << " " << std::endl;
	wrongmeta->makeSound();
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();
	std::cout << std::endl;

	delete wrongmeta;
	std::cout << std::endl;
	delete wrongcat;

	return 0;
}