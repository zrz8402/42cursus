/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:17:56 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 13:04:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <iostream>

class Brain {

private:
	std::string	ideas[100];

public:
	Brain( void );
	Brain( const Brain &other );
	Brain& operator=( const Brain &other );
	~Brain( void );

	void	setIdea( int index, const std::string &idea);
	void	setIdeas( const std::string (&ideas)[100] );

	const std::string*	getIdeas( void ) const;
};

#endif