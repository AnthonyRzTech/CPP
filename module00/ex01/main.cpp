/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:59:38 by anthrodr          #+#    #+#             */
/*   Updated: 2024/02/06 08:59:46 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

std::string readNonEmptyInput(const std::string& prompt, const std::string& error_message) {
    std::string input;
    std::cout << prompt;
    while (std::getline(std::cin, input), input.empty()) {
        std::cout << error_message;
    }
    return input;
}

Contact readContactInfo() {
    Contact contact;

    contact.setFirstName(readNonEmptyInput("Enter first name: ", "First name cannot be empty. Please enter first name: "));
    contact.setLastName(readNonEmptyInput("Enter last name: ", "Last name cannot be empty. Please enter last name: "));
    contact.setNickname(readNonEmptyInput("Enter nickname: ", "Nickname cannot be empty. Please enter nickname: "));
    contact.setPhoneNumber(readNonEmptyInput("Enter phone number: ", "Phone number cannot be empty. Please enter phone number: "));
    contact.setDarkestSecret(readNonEmptyInput("Enter darkest secret: ", "Darkest secret cannot be empty. Please enter darkest secret: "));

    return contact;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact(readContactInfo());
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::cout << "Enter the index of the contact to display: ";
            int index;

            while (!(std::cin >> index)) {
                if (std::cin.eof()) {
                    return 0;
                } else if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid index. Please enter a valid numeric index: ";
                }
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phoneBook.displayContact(index);
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}

