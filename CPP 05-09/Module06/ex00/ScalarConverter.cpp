/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:34:15 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 19:01:17 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    this->ctrlChar = 0;
    this->n_int = 0;
    this->n_char = '\0';
    this->n_float = 0.0;
    this->n_double = 0.0;
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::ScalarConverter(std::string data)
{
    this->Convert(data);
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter&  ScalarConverter::operator=(ScalarConverter &pointer)
{
    this->ctrlChar = pointer.ctrlChar;
    this->n_int = pointer.n_int;
    this->n_char = pointer.n_char;
    this->n_float = pointer.n_float;
    this->n_double = pointer.n_double;

    return (*this);
}

void    ScalarConverter::ConvertInt(std::string data)
{
    try
    {
        if (this->CheckChar(data) == false)
            this->n_int = static_cast<int>(std::stoi(data));
        else
            this->n_int = ctrlChar;
        std::cout << "int\t= " << n_int << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "int\t= impossible" << '\n';
    }
}

void    ScalarConverter::ConvertChar(std::string data)
{
    try
    {
        if (this->CheckChar(data) == false && (std::stoi(data) < 32 || std::stoi(data) > 126))
            std::cout << "char\t= Non Displayable" << std::endl;
        else
        {
            if (this->CheckChar(data) == false)
                this->n_char = static_cast<char>(std::stoi(data));
            else
                this->n_char = data[0];
            std::cout << "char\t= '" << n_char << "'" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "char\t= impossible" << '\n';
    }
}

void    ScalarConverter::ConvertFloat(std::string data)
{
    try
    {
        if (this->CheckChar(data) == false)
        {
            this->n_float = static_cast<float>(std::stof(data));
            if ((this->CheckFloat(data) == true || data == "+inff" || data == "-inff"
                || data == "nan" || data == "nanf" || data == "+inf" || data == "-inf") 
                && this->n_float - static_cast<int>(n_float) != 0)
                std::cout << "float\t= " << n_float << "f" << std::endl;
            else
                std::cout << "float\t= " << n_float << ".0f" << std::endl;
        }
        else
        {
            this->n_float = static_cast<float>(ctrlChar);
            std::cout << "float\t= " << n_float << ".0f" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "float\t= impossible" << '\n';
    }
}

void    ScalarConverter::ConvertDouble(std::string data)
{
    try
    {
        if (this->CheckChar(data) == false)
        {
            this->n_double = static_cast<double>(std::stod(data));
            if (((this->CheckDouble(data) == true || this->CheckFloat(data) == true)
                || data == "+inff" || data == "-inff" || data == "nan" || data == "nanf"
                || data == "+inf" || data == "-inf") && n_double - static_cast<int>(n_double) != 0)
                std::cout << "double\t= " << n_double << std::endl;
            else
                std::cout << "double\t= " << n_double << ".0" << std::endl;
        }
        else
        {
            this->n_double = static_cast<double>(ctrlChar);
            std::cout << "double\t= " << n_double << ".0" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "double\t= impossible" << '\n';
    }
}

void    ScalarConverter::Convert(std::string data)
{
    if (this->CheckChar(data) == false && this->CheckInt(data) == false
        && this->CheckFloat(data) == false && this->CheckDouble(data) == false
        && data != "nan" && data != "-inff" && data != "+inff" && data != "nanf"
        && data != "-inf" && data != "+inf")
    {
        std::cerr << "Error, unknown type\n";
        return ;
    }
    if (this->CheckChar(data) == true)
        ctrlChar = static_cast<int>(data[0]);
    this->ConvertInt(data);
    this->ConvertChar(data);
    this->ConvertFloat(data);
    this->ConvertDouble(data);
}

bool    ScalarConverter::CheckChar(std::string data)
{
    if (((data[0] >= 32 && data[0] < '0') || (data[0] > '9' && data[0] < 127))
        && data.length() < 2)
        return (true);
    return (false);
}

bool    ScalarConverter::CheckInt(std::string data)
{
    int i;

    i = 0;
    while (data[i] != '\0')
    {
        if ((data[i] < '0' && data[i] != '-' && data[i] != '+') || data[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

bool    ScalarConverter::CheckFloat(std::string data)
{
    int i;
    int point;
    int flt;

    i = 0;
    point = 0;
    flt = 0;
    while (data[i] != '\0')
    {
        if (data[i] == '.' && i > 0 && data[i + 1] != '\0')
            point++;
        if (data[i] == 'f' && point > 0 && data[i - 1] != '.')
            flt++;
        if (((data[i] < '0' && i == 0) || (data[i] < '0' && data[i] != '.')
            || (data[i] > '9' && data[i] != 'f')) && data[i] != '-' && data[i] != '+')
            return (false);
        i++;
    }
    if (point != 1 && flt != 1)
        return (false);
    return (true);
}

bool    ScalarConverter::CheckDouble(std::string data)
{
    int i;
    int point;

    i = 0;
    point = 0;
    while (data[i] != '\0')
    {
        if (data[i] == '.' && i > 0 && data[i + 1] != '\0')
            point++;
        if (((data[i] < '0' && i == 0) || (data[i] < '0' && data[i] != '.')
            || (data[i] > '9')) && data[i] != '-' && data[i] != '+')
            return (false);
        i++;
    }
    if (point != 1)
        return (false);
    return (true);
}
