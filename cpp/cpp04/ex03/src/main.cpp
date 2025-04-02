/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 15:58:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void	testMateriaSource(void) {
	IMateriaSource* src = new MateriaSource();
	ICharacter* 	me = new Character("me");
	AMateria* 		materia;
	AMateria* 		tmp;

	// no ice materia
	materia = src->createMateria("ice");
	// passing NULL
	me->equip(materia);
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// MateriaSource inventory is full
	src->learnMateria(new Cure());
	std::cout << std::endl;

	materia = src->createMateria("ice");
	// save it to clean
	tmp = materia;
	materia = src->createMateria("cure");
	std::cout << std::endl;

	delete tmp;
	delete materia;
	delete me;
	delete src;	
}

void	testCharacter()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");

	AMateria* materia;
	materia = src->createMateria("ice");
	me->equip(materia);
	std::cout << std::endl;

	materia = src->createMateria("cure");
	// save this for unequip()
	AMateria* tmp = materia;
	me->equip(materia);
	std::cout << std::endl;

	materia = src->createMateria("ice");
	me->equip(materia);
	std::cout << std::endl;

	materia = src->createMateria("cure");
	me->equip(materia);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	std::cout << std::endl;

	me->unequip(5);
	me->unequip(1);
	me->unequip(1);
	me->use(1, *bob);
	std::cout << std::endl;

	delete tmp;
	delete bob;
	delete me;
	delete src;

}

int main()
{
	std::cout << "--------TEST MateriaSource--------" << std::endl;
	testMateriaSource();
	std::cout << "--------TEST Character--------" << std::endl;
	testCharacter();
	return 0;
}
