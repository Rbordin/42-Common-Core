/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:42 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/27 16:14:14 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchanger.hpp"

int	main(int ac, char **av)
{
    BitcoinExchanger                prova;
    std::map<std::string, float>    input;
	std::ifstream	                file;
    if (ac != 2)
    {
        std::cerr << "you have to enetr file for the program to work" << std::endl;
        return (-1);
    }
	file.open(av[1]);
    std::string line;
    getline(file, line, '\n');
    std::string date;
    float   value;
    std::map<std::string, float>::iterator i;
    while (std::getline(file, line))
    {
        date = line.substr(0, 10);
        size_t find = line.find('|') + 1;
        sscanf(line.c_str() + find, "%f", &value);
        input[date] = value;
    }
    i = input.begin();
    prova.checker(input);
    file.close();
    return 0;
}