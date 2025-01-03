/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 12:31:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA {

private:
	std::string	name;
	Weapon		&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack() const;
};

#endif