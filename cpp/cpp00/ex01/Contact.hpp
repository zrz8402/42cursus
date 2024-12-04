/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:24:51 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 12:29:00 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();

	void   setFirstName(const std::string& newFirstName);
	void   setLastName(const std::string& newLastName);
	void   setNickname(const std::string& newNickname);
	void   setPhoneNumber(const std::string& newPhoneNumber);
	void   setDarkestSecret(const std::string& newDarkestSecret);

	std::string   getFirstName() const;
	std::string   getLastName() const;
	std::string   getNickname() const;
	std::string   getPhoneNumber() const;
	std::string   getDarkestSecret() const;
};

#endif