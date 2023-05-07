/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadFile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:18:38 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/15 12:25:45 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>

class ReadFile
{
private:
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     read;
public:
    ReadFile(std::string _file);
    ~ReadFile();
    void    SaveFile(void);
    void    ReplaceString(std::string last, std::string str);
    void    SaveToFileReplace(void);
};

#endif