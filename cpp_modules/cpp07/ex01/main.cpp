/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:38:23 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 16:07:00 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int testInt[7] = {1, 2, 3, 4, 5, 6, 7};
	std::string testStr[4] = {"ciao", "riccardo", "come", "stai"};

	std::cout << "array di int prima di iter"<< std::endl;
	for (unsigned long i = 0; i < 7; i++)
		std::cout << testInt[i] << std::endl;
	std::cout << "array di str prima di iter"<< std::endl;
	for (unsigned long i = 0; i < 4; i++)
		std::cout << testStr[i] << std::endl;
	iter(testInt, 7, toDo);
	iter(testStr, 4, toDo);
	std::cout << "array di int dopo di iter"<< std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << testInt[i] << std::endl;
	std::cout << "array di str dopo di iter"<< std::endl;
	for (unsigned long i = 0; i < 4; i++)
		std::cout << testStr[i] << std::endl;
}