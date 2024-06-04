/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:45:51 by riccardobor       #+#    #+#             */
/*   Updated: 2023/08/11 16:14:17 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN!";
	std::string *strPTR = &str;
	std::string &strREF = str;
	
	std::cout << "Memory address of the string : " << &str << std::endl;
	std::cout << "Memory address of the string pointer : " << strPTR << std::endl;
	std::cout << "Memory address of the string reference : " << &strREF << std::endl;

	std::cout << "value of string : " << str << std::endl;
	std::cout << "value of string pointer : " << *strPTR << std::endl;
	std::cout << "value of string reference : " << strREF << std::endl;
}