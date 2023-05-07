/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:51:59 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/19 19:09:26 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

Contact::Contact(void)
{
    firstName       = "          ";
    lastName        = "          ";
    nickname        = "          ";
    phoneNumber     = "          ";
    secret          = "          ";
}

void    Contact::ContactPrint(int i)
{
    std::cout  << "         " << (i + 1) << "|";
    ContactPrintTrunk(firstName);
    ContactPrintTrunk(lastName);
    ContactPrintTrunk(nickname);
    std::cout << std::endl;
}

void    Contact::ContactAdd(void)
{
    firstName = ContactData("First name: ");
    lastName = ContactData("Last Name: ");
    nickname = ContactData("Nick Name: ");
    phoneNumber = ContactDataNumber("Phone Number: ");
    secret = ContactData("Darkest Secret: ");
    system ("clear");
}

void    Contact::ContactPrintContact(void)
{
    std::cout << "First name:     " << firstName << std::endl;
    std::cout << "Last name:      " << lastName << std::endl;
    std::cout << "NickName:       " << nickname << std::endl;
    std::cout << "Phone Number:   " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << secret << std::endl;
}

std::string    Contact::ContactData(std::string data)
{
    std::string entry;

    std::cout << data;
    std::getline(std::cin, entry);
    while (((!isprint(entry[0]) && entry[0] != -61)
        || ContentAlpha(entry) == 1) && !std::cin.eof())
    {
        std::cout << data;
        std::getline(std::cin, entry);
    }
    return (entry);
}

std::string    Contact::ContactDataNumber(std::string data)
{
    std::string entry;

    std::cout << data;
    std::getline(std::cin, entry);
    while ((!isprint(entry[0]) || CheckNumberEntry(entry) == 1) && !std::cin.eof())
    {
        std::cout << data;
        std::getline(std::cin, entry);
    }
    return (entry);
}

void    Contact::ContactPrintTrunk(std::string data)
{
    int i;

    if (StrlenSpc(data) <= 10)
    {
        i = 10 - StrlenSpc(data);
        while (i > 0)
        {
            std::cout << " ";
            i--;
        }
        std::cout << data << "|";
    }
    else
    {
        StdoutSpc(data);
        std::cout << ".|";
    }
}

void    Contact::StdoutSpc(std::string data)
{
    std::string sub_data (data, 0, 9);
    int         x;
    int         i;

    i = 0;
    x = 0;
    while(x < 10)
    {
        if (data[x] >= 32 && data[x] <= 126)
            i++;
        x++;
    }
    if (x - i != 0)
    {
        x = (x - i)/ 2;
        i = i + x;
        while (data[++i])
            data[i] = '\0';
        std::cout << data;
    }
    else
        std::cout << sub_data;
}

int     Contact::StrlenSpc(std::string data)
{
    int i;
    int x;

    i = 0;
    x = 0;
    while (data[x] != '\0')
    {
        if (data[x] >= 32 && data[x] <= 126)
            i++;
        x++;
    }
    if (x - i != 0)
    {
        x = (x - i)/ 2;
        i = i + x;
    }
    return (i);
}

int     Contact::ContentAlpha(std::string entry)
{
    int i;

    i = 0;
    while (entry[i] != '\0')
    {
        if (isprint(entry[i]) && entry[i] != 32)
            return (0);
        i++;
    }
    return (1);
}

int Contact::CheckNumberEntry(std::string entry)
{
    int i;

    i = 0;
    while (entry[i])
    {
        if((entry[i] < '0' || entry[i] > '9') && entry[i] != ' ' && entry[i] != '+')
            return (1);
        i++;
    }
    return (0);
}
