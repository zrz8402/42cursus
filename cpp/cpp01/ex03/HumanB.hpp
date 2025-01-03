/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 12:35:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB {

private:
	std::string	name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif