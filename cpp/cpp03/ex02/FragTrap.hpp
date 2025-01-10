/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:08 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 16:06:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap(std::string name);
	FragTrap( const FragTrap &other );
	FragTrap& operator=( const FragTrap &other );
	~FragTrap();

	// void	attack( const std::string& target );
	void	highFivesGuys( void );
};

#endif