/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 14:54:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

// <NAME>: My job here is done!
Warlock::~Warlock() {
	std::cout  << name << ": My job here is done!" << std::endl;
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		delete *it;
	}
	spells.clear();
}

const std::string&	Warlock::getName() const {
	return name;
}

const std::string&	Warlock::getTitle() const {
	return title;
}

void	Warlock::setTitle(const std::string &title) {
	this->title = title;
}

// "<NAME>: I am <NAME>, <TITLE>!"
void	Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
			if ((*it)->getName() == spell->getName()) {
				return ;
			}
		}
		spells.push_back(spell->clone());
	}
}

void	Warlock::forgetSpell(std::string const &name) {
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		if ((*it)->getName() == name) {
			delete *it;
			spells.erase(it);
			break;
		}
	}
}

void	Warlock::launchSpell(std::string const &name, ATarget &target) {
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		if ((*it)->getName() == name) {
			(*it)->launch(target);
			break;
		}
	}
}