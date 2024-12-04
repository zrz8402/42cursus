/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:43 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 14:47:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon {

private:
	std::string	type;

public:
	Weapon();
	~Weapon();

	void	setType(std::string newType);

	std::string	getType();
};