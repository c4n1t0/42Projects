/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:17:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 19:04:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private:
        int     ctrlChar;
        int     n_int;
        char    n_char;
        float   n_float;
        double  n_double;
        
        bool    CheckChar(std::string data);
        bool    CheckInt(std::string data);
        bool    CheckFloat(std::string data);
        bool    CheckDouble(std::string data);
        void    ConvertInt(std::string data);
        void    ConvertChar(std::string data);
        void    ConvertFloat(std::string data);
        void    ConvertDouble(std::string data);

    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter &copy);
        ScalarConverter(std::string data);
        ~ScalarConverter();

        ScalarConverter&    operator=(ScalarConverter &pointer);
        void                Convert(std::string data);
};

#endif
