/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:21:56 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/16 13:21:59 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

class   Harl
{
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        Harl(void);
        ~Harl(void);
        void complain( std::string level );
};

typedef void(Harl::*function) (void);

#endif