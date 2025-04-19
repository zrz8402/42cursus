/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 18:58:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() : type() {}

ATarget::ATarget(std::string const &type) : type(type) {}

ATarget::ATarget(const ATarget &other) : type(other.type) {}

ATarget& ATarget::operator=(const ATarget &other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

ATarget::~ATarget() {}

const std::string&	ATarget::getType() const {
	return type;
}

// <TYPE> has been <EFFECTS>!
void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
