/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:55:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 17:20:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (std::vector<ATarget*>::iterator it = types.begin(); it != types.end(); ++it) {
		delete *it;
	}
	types.clear();
}


void	TargetGenerator::learnTargetType(ATarget* type) {
	if (type) {
		for (std::vector<ATarget*>::iterator it = types.begin(); it != types.end(); ++it) {
			if ((*it)->getType() == type->getType()) {
				return ;
			}
		}
		types.push_back(type->clone());
	}
}

void	TargetGenerator::forgetTargetType(std::string const &type) {
    for (std::vector<ATarget*>::iterator it = types.begin(); it != types.end(); ++it) {
        if ((*it)->getType() == type) {
            delete *it;
            types.erase(it);
			break;
        }
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &type) {
	for (std::vector<ATarget*>::iterator it = types.begin(); it != types.end(); ++it) {
		if ((*it)->getType() == type) {
			return (*it);
		}
	}
	return NULL;
}
