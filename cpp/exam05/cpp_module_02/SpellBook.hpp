/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:57:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 14:36:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include "ASpell.hpp"
#include <vector>

class ASpell;
class SpellBook {

private:
	std::vector<ASpell*> spells;

	SpellBook(const SpellBook &other);
	SpellBook& operator=(const SpellBook &other);

public:
	SpellBook();
	virtual	~SpellBook();

	void	learnSpell(ASpell* spell);
	void	forgetSpell(std::string const &name);
	ASpell*	createSpell(std::string const &name);
};

#endif