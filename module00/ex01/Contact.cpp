/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:59:27 by anthrodr          #+#    #+#             */
/*   Updated: 2024/02/06 08:59:30 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string& fname) {
    first_name = fname;
}

void Contact::setLastName(const std::string& lname) {
    last_name = lname;
}

void Contact::setNickname(const std::string& nname) {
    nickname = nname;
}

void Contact::setPhoneNumber(const std::string& phone) {
    phone_number = phone;
}

void Contact::setDarkestSecret(const std::string& secret) {
    darkest_secret = secret;
}

std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}
