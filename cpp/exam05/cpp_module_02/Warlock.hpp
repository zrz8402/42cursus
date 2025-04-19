/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/19 11:14:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <vector>
#include <iterator>

class Warlock {

private:
	std::string	name;
	std::string	title;

	SpellBook spellBook;
	
	Warlock();
	Warlock(const Warlock &other);
	Warlock& operator=(const Warlock &other);

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	const std::string&	getName() const;
	const std::string&	getTitle() const;

	void	setTitle(const std::string &title);

	void	introduce() const;

	void	learnSpell(ASpell* spell);
	void	forgetSpell(std::string const &name);
	void	launchSpell(std::string const &name, ATarget &target);
};

#endif