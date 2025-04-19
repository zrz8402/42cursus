/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:43:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 17:57:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {

private:
	std::string	name;
	std::string	title;

	Warlock();
	Warlock(const Warlock &other);
	Warlock& operator=(const Warlock &other);

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	const std::string&	getName() const;
	const std::string&	getTitle() const;

	void	setTitle(const std::string &title);

	void	introduce() const;
};

#endif