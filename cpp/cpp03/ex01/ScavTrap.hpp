/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:08 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 15:26:32 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap(std::string name);
	ScavTrap( const ScavTrap &other );
	ScavTrap& operator=( const ScavTrap &other );
	~ScavTrap();

	void	attack( const std::string& target );
	void	guardGate();
};

#endif