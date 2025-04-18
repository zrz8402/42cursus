/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 19:18:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

// <NAME>: My job here is done!
Warlock::~Warlock() {
	std::cout  << name << ": My job here is done!" << std::endl;
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
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
		std::vector<ASpell*>::iterator ite = spells.end();
		for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
			if ((*it)->getName() == spell->getName()) {
				return ;
			}
		}
		spells.push_back(spell->clone());
	}
}

void	Warlock::forgetSpell(std::string const &name) {
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name) {
			delete *it;
			it = spells.erase(it);
		}
	}
}

void	Warlock::launchSpell(std::string const &name, ATarget &target) {
	std::vector<ASpell*>::iterator ite = spells.end();
	for (std::vector<ASpell*>::iterator it = spells.begin(); it != ite; it++) {
		if ((*it)->getName() == name) {
			(*it)->launch(target);
			return ;
		}
	}
}