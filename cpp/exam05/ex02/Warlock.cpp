/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 11:16:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

// <NAME>: My job here is done!
Warlock::~Warlock() {
	std::cout  << name << ": My job here is done!" << std::endl;
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
	spellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string const &name) {
	spellBook.forgetSpell(name);
}

void	Warlock::launchSpell(std::string const &name, ATarget &target) {
	ASpell *spell = spellBook.generateSpell(name);
	if (spell) {
		spell->launch(target);
	}
}