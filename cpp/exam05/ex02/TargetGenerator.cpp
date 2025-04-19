/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:55:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 11:21:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::vector<ATarget*>::iterator ite = types.end();
	for (std::vector<ATarget*>::iterator it = types.begin(); it != ite; it++) {
		delete *it;
	}
	types.clear();
}


void	TargetGenerator::learnTargetType(ATarget* type) {
	if (type) {
		std::vector<ATarget*>::iterator ite = types.end();
		for (std::vector<ATarget*>::iterator it = types.begin(); it != ite; it++) {
			if ((*it)->getType() == type->getType()) {
				return ;
			}
		}
		types.push_back(type->clone());
	}
}

void	TargetGenerator::forgetTargetType(std::string const &name) {
	std::vector<ATarget*>::iterator ite = types.end();
	for (std::vector<ATarget*>::iterator it = types.begin(); it != ite; it++) {
		if ((*it)->getType() == name) {
			delete *it;
			it = types.erase(it);
		}
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &name) {
	std::vector<ATarget*>::iterator ite = types.end();
	for (std::vector<ATarget*>::iterator it = types.begin(); it != ite; it++) {
		if ((*it)->getType() == name) {
			return (*it);
		}
	}
	return NULL;
}