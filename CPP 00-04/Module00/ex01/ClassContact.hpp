/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:09:40 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/22 01:11:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;

        std::string ContactData(std::string data);
        std::string ContactDataNumber(std::string data);
        void        ContactPrintTrunk(std::string data);
        void        StdoutSpc(std::string data);
        int         StrlenSpc(std::string data);
        int         ContentAlpha(std::string entry);
        int         CheckNumberEntry(std::string entry);
        
    public:
        Contact();
        void ContactPrint(int i);
        void ContactAdd(void);
        void ContactPrintContact();
};

#endif