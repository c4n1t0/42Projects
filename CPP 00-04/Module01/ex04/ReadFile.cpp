/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:18:04 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/06 20:57:11 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReadFile.hpp"

ReadFile::ReadFile(std::string _file)
{
    std::string replace = _file + ".replace";
    
    infile.open(_file);
    if (infile.fail())
    {
        std::cout << "Failed open file" << std::endl;
        exit (1);
    }
    outfile.open(replace, std::ios::out);
    if (outfile.fail())
    {
        std::cout << "Failed to create out file" << std::endl;
        exit (1);
    }
}

ReadFile::~ReadFile()
{
    infile.close();
    outfile.close();
}

void    ReadFile::SaveFile(void)
{
    std::string str;
    int count;

    count = 0;
    while (!infile.eof())
    {
        getline(infile, str);
        if (count)
            this->read = read + "\n" + str;
        else
            this->read = read + str;
        count++;
    }
}

void    ReadFile::ReplaceString(std::string last, std::string str)
{
    std::string temp;
    size_t      i;
    
    if (last.empty() || str.empty())
    {
        std::cout << "Invalid arguments to replace" << std::endl;
        exit (1);
    }
    if (read.find(last) == std::string::npos)
        std::cout << "String to replace not found on file" << std::endl;
    else
    {
        i = 0;;
        while (read.find(last, i) != std::string::npos)
        {
            i = read.find(last, i);
            read.erase(i, last.length());
            read.insert(i, str);
            i = i + str.length();
            if (i == 0)
                i++;
        }
    }
}

void    ReadFile::SaveToFileReplace(void)
{
    this->outfile << this->read;
}
