/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:08:13 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 16:12:13 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	harl test;
	std::string input;

	std::cout << "What message do you want? " << std::endl;
	std::cin >> input;
	test.complain(input);
	return (0);
}