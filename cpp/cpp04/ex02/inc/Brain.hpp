/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:17:56 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:16:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain {

private:
	std::string	ideas[100];

public:
	Brain( void );
	Brain( const std::string ideas[100] );
	Brain( const Brain &other );
	Brain& operator=( const Brain &other );
	~Brain( void );

	void	setIdea( int index, const std::string &idea);
	void	setIdeas( const std::string (&ideas)[100] );

	std::string		getIdea( int index ) const;
	const std::string*	getIdeas( void ) const;
};

#endif