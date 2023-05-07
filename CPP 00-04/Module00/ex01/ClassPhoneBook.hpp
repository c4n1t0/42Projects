/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:14:30 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/22 21:18:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "ClassContact.hpp"

class PhoneBook
{
    private:
        int     index;
        Contact contactos[8];

        int     CheckDisplay(std::string input);
        void    PrintTable(void);
        
    public:
        PhoneBook(void);
        void    Welcome(void);
        void    Options(void);
        void    EXIT(void);
        void    SEARCH(std::string input);
        void    ADD(void);
};

#endif