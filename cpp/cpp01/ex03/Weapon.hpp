/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 12:16:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <iostream>

class Weapon {

private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string	type);
	~Weapon();

	void	setType(const std::string &type);

	const std::string	&getType() const;
};

#endif