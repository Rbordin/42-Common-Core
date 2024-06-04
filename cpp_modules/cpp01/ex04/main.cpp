/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:41:22 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 12:41:24 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string file_name;
	std::string s1;
	std::string s2;
	std::string line;

	std::cout << "What file do you wanna read? ";
	std::cin >> file_name;
	std::cout << "What phrase/word you wanna replace in the file? ";
	std::cin >> s1;
	std::cout << "What phrase/word do you wanna use instead? ";
	std::cin >> s2;
	
	std::ifstream file(file_name);
	if (!file.is_open())
	{
		std::cerr << "error in opening input file" << std::endl;
		return (-1);
	}
	std::ofstream output(file_name + ".replace");
	if(!output.is_open())
	{
		std::cerr << "error in opening output file" << std::endl;
	}
	while (getline(file, line, '\n'))
	{
		if (line.find(s1) != std::string::npos)
		{
			output << line.substr(0, line.find(s1, 0));
			output << s2;
			output << line.substr(line.find(s1, 0) + s1.size()) << std::endl;
		}
		else
			output << line << std::endl;
	}
	file.close();
	output.close();
}
