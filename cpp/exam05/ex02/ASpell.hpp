/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 18:59:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell {

private:
	std::string	name;
	std::string	effects;

public:
	ASpell();
	ASpell(std::string const &name, std::string const &effects);
	ASpell(const ASpell &other);
	ASpell& operator=(const ASpell &other);
	virtual	~ASpell();

	const std::string&	getName() const;
	const std::string&	getEffects() const;

	virtual ASpell*	clone() const = 0;

	void	launch(const ATarget &target) const;
};

#endif