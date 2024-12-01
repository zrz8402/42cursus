/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:09 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/01 13:08:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "Contact.hpp"

class PhoneBook {

private:
	Contact     phonebook[8];
	int         size;
	int         oldestContact;

public:
	PhoneBook();
	~PhoneBook();
	int     getSize();
	void    saveContact(const Contact& newContact);
	void    displayContact(int i);
};

#endif