/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:12:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;

	std::cout << "---------------------------" << std::endl;
	const int	size = 4;
	Animal		*animals[size];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
			std::cout << std::endl;
		} else {
			animals[i] = new Cat();
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < size; i++){
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < size; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
	

	return 0;
}