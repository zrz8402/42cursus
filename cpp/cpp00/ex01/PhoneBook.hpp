/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:09 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 12:35:59 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "Contact.hpp"

class PhoneBook {

private:
	Contact     phonebook[8];
	int			size;
	int         index;

public:
	PhoneBook();
	~PhoneBook();

	void	add();
	void	search();
	void    displayContact(int i);
};

#endif