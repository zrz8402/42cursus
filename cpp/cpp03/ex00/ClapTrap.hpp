/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 11:57:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {

private:
	std::string		name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	damage;

public:
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap &other );
	ClapTrap& operator=( const ClapTrap &other );
	~ClapTrap();

	void	setHp( const unsigned int hp );
	void	setEp( const unsigned int ep );
	void	setDamage( const unsigned int damage );

	std::string		getName() const;
	unsigned int	getHp() const;
	unsigned int	getEp() const;
	unsigned int	getDamage() const;

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif