/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:08 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 18:10:02 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap &other );
	FragTrap& operator=( const FragTrap &other );
	virtual ~FragTrap();

	void	highFivesGuys( void );
};

#endif