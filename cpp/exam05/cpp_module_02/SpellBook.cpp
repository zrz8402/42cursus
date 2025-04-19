/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 14:54:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		delete *it;
	}
	spells.clear();
}


void	SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
			if ((*it)->getName() == spell->getName()) {
				return ;
			}
		}
		spells.push_back(spell->clone());
	}
}

void	SpellBook::forgetSpell(std::string const &name) {
    for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            spells.erase(it);
			return ;
        }
    }
}

ASpell*	SpellBook::createSpell(std::string const &name) {
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		if ((*it)->getName() == name) {
			return (*it);
		}
	}
	return NULL;
}