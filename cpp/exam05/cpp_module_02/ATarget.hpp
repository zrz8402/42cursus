/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 18:58:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {

private:
	std::string	type;

public:
	ATarget();
	ATarget(std::string const &type);
	ATarget(const ATarget &other);
	ATarget& operator=(const ATarget &other);
	virtual	~ATarget();

	const std::string&	getType() const;

	virtual ATarget*	clone() const = 0;

	void	getHitBySpell(const ASpell &spell) const;
};

#endif