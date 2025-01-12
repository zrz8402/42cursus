/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:13:19 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/12 11:18:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DiamondTRAP_HPP__
#define __DiamondTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string	name;

public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &other );
	DiamondTrap& operator=( const DiamondTrap &other );
	~DiamondTrap( void );

	void	whoAmI( void );
	std::string		getName( void ) const;
};


#endif