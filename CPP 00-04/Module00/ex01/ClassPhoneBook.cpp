/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 09:14:42 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/22 21:18:37 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    int i;

    i = 0;
    while (i < 8)
    {
        contactos[i] = Contact();
        i++;
    }
	index = 0;
}

void    PhoneBook::Welcome(void)
{
    system("clear");
    std::cout << "Welcome to My Awesome PhoneBook\n" << std::endl;
    Options();
}

void    PhoneBook::Options(void)
{
    std::cout << "What do you need?" << std::endl;
    std::cout << "These options are available: ADD, SEARCH, EXIT.\n" << std::endl;
    std::cout << "ADD:\n\tAdd a new contact to PhoneBook. Remember! ";
    std::cout << "Only 8 slots are available." << std::endl;
    std::cout << "\tIf PhoneBook slots is full, the oldest contact will replace." << std::endl;
    std::cout << "SEARCH:\n\tDisplay a specific contact from PhoneBook." << std::endl;
    std::cout << "EXIT:\n\tGo out from My Awesome PhoneBook\n" << std::endl;
}

void    PhoneBook::EXIT(void)
{
    system("clear");
    std::cout << "\n\tSee you later!" << std::endl;
    exit (0);
}

void    PhoneBook::SEARCH(std::string input)
{
	PrintTable();
    if (index > 0)
    {
        std::cout << "What contact do you want to show? ";
        std::getline(std::cin, input);
        while (CheckDisplay(input) == 1 && !std::cin.eof())
        {
            std::cout << "\nInvalid index, try again!" << std::endl;
            std::cout << "What contact do you want to show? ";
 	        std::getline(std::cin, input);
        }
        if (std::cin.eof() == true)
        {
	    	system("clear");
            std::cout << "\n\tSee you later!" << std::endl;
            exit(0);
        }
        contactos[std::stoi(input) - 1].ContactPrintContact();
    }
    else
        std::cout << "\nThe PhoneBook is empty!" << std::endl;
    std::cout << "\nPress enter to continue..." << std::endl;
    system("read");
    system("clear");
    Options();
}

void	PhoneBook::ADD(void)
{
	std::cout << std::endl;
	contactos[index % 8].ContactAdd();
    index++;
    Options();
}

int     PhoneBook::CheckDisplay(std::string input)
{
    int num;

    if (input.length() > 1 || input[0] >= '9' || input[0] <= '0')
        return (1);
    num = std::stoi(input);
    if (index < 8 && num > index)
        return (1);
    return (0);
}

void    PhoneBook::PrintTable(void)
{
    int	i;
	
    std::cout << "\nSearching list...\n" << std::endl;
	i = 0;
    std::cout << "     index|First Name| Last Name|  NickName|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (i < 8)
    {
        contactos[i].ContactPrint(i);
        i++;
    }
}
