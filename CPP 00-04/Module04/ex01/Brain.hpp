/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:53:18 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:11:45 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
        
    public:
        Brain(void);
        Brain(const Brain &copy);
        virtual ~Brain(void);

        Brain& operator=(const Brain &pointer);
};

#endif