/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 11:13:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
		delete *it;
	}
	spells.clear();
}


void	SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ite = spells.end();
		for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
			if ((*it)->getName() == spell->getName()) {
				return ;
			}
		}
		spells.push_back(spell->clone());
	}
}

void	SpellBook::forgetSpell(std::string const &name) {
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name) {
			delete *it;
			it = spells.erase(it);
		}
	}
}

ASpell*	SpellBook::generateSpell(std::string const &name) {
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name) {
			return (*it);
		}
	}
	return NULL;
}