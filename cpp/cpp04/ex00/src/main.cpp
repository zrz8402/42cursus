/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 13:14:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n----WrongAnimal----" <<std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << wrongmeta->getType() << " " << std::endl;
	wrongmeta->makeSound();
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();

	delete wrongmeta;
	delete wrongcat;

	return 0;
}