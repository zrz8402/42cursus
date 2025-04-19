/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 19:00:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() : name(), effects() {}

ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell &other) : name(other.name), effects(other.effects) {}

ASpell& ASpell::operator=(const ASpell &other) {
	if (this != &other) {
		name = other.name;
		effects = other.effects;
	}
	return *this;
}

ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {
	return name;
}

const std::string&	ASpell::getEffects() const {
	return effects;
}

void	ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}