/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainPhoneBook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:17:48 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/22 21:18:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhoneBook.hpp"

int main(void)
{
    std::string input;
    PhoneBook book;
    
    book = PhoneBook();
    book.Welcome();
    
    while (42)
    {
        std::cout << "Select your option> ";
        std::getline(std::cin, input);
        if (std::cin.eof() || input.compare("EXIT") == 0)
            book.EXIT();
        else if (input.compare("SEARCH") == 0)
            book.SEARCH(input);
        else if (input.compare("ADD") == 0)
            book.ADD();
        else
        {
            system("clear");
            std::cout << "\nInvalid command...\n" << std::endl;
            book.Options();
        }
    }
    return (0);
}
