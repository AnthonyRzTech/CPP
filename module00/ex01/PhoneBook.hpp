/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:00:07 by anthrodr          #+#    #+#             */
/*   Updated: 2024/02/06 09:00:13 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int contact_count;

public:
    PhoneBook();

    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContact(int index) const;

private:
    std::string truncateString(const std::string& str) const;
};

#endif

