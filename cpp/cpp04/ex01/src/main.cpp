/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 13:12:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	testBasic(void) {
	{
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
	}
}

void	testBrain(void) {
	{
		Brain	*tom = new Brain();
		Brain	*jerry = new Brain();
		std::cout << std::endl;

		jerry->setIdea(0, "1st idea");
		std::cout << "jerry 1st idea: " << jerry->getIdeas()[0] << std::endl;
		Brain	*ron = new Brain(*jerry);
		std::cout << "ron 1st idea: " << ron->getIdeas()[0] << std::endl;
		*tom = *jerry;
		std::cout << "tom 1st idea: " << tom->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		jerry->setIdea(0, "new 1st idea");
		std::cout << "jerry 1st idea: " << jerry->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		std::cout << "ron 1st idea: " << ron->getIdeas()[0] << std::endl;
		std::cout << "tom 1st idea: " << tom->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		delete jerry;
		delete ron;
		delete tom;
		std::cout << std::endl;
	}
}

void	testCat()
{
	{
		Cat	*ron = new Cat();
		std::cout << std::endl;
		Cat	*rocket = new Cat();
		std::cout << std::endl;

		rocket->getBrain()->setIdea(0, "first idea");
		*ron = *rocket;
		std::cout << std::endl;

		std::cout << "ron 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "rocket 1st idea: " << rocket->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		ron->getBrain()->setIdea(0, "change my mind");
		std::cout << "ron 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "rocket 1st idea: " << rocket->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		Cat	*tom = new Cat(*ron);
		std::cout << std::endl;

		std::cout << "rocket 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "tom 1st idea: " << tom->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		delete rocket;
		delete tom;
		delete ron;
		std::cout << std::endl;
	}
}

void	testDog()
{
	{
		Dog	*ron = new Dog();
		std::cout << std::endl;
		Dog	*rocket = new Dog();
		std::cout << std::endl;

		rocket->getBrain()->setIdea(0, "first idea");
		*ron = *rocket;
		std::cout << std::endl;

		std::cout << "ron 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "rocket 1st idea: " << rocket->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		ron->getBrain()->setIdea(0, "change my mind");
		std::cout << "ron 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "rocket 1st idea: " << rocket->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		Dog	*tom = new Dog(*ron);
		std::cout << std::endl;

		std::cout << "rocket 1st idea: " << ron->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "tom 1st idea: " << tom->getBrain()->getIdeas()[0] << std::endl;
		std::cout << std::endl;

		delete rocket;
		delete tom;
		delete ron;
		std::cout << std::endl;
	}
}

int main() {
	testBasic();
	testBrain();
	testCat();
	testDog();

	return 0;
}