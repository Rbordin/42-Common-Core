/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:49:57 by rbordin           #+#    #+#             */
/*   Updated: 2023/10/03 12:17:31 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string input;

	std::cout << "Choose a name for your personal zombie: ";
	std::cin >> input;
	zombie monster(input);
	monster.announce();
	randomChump(input + "_random");
}