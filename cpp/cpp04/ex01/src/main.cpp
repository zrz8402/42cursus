/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:08:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();

	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}