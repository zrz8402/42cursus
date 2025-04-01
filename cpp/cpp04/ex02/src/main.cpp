/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:43:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const AAnimal* dog = new Dog();
	std::cout << std::endl;
	const AAnimal* cat = new Cat();
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

	{
		Animal*	animal = new Animal();
		delete animal;
		Animal	animal1;
	}

	// NOT ALLOWED
	// {
	// 	AAnimal*	animal = new AAnimal();
	// 	delete aAnimal;
	// 	AAnimal	aAnimal1;
	// }

	return 0;
}