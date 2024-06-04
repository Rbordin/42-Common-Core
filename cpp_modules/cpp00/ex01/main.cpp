/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:44:53 by riccardobor       #+#    #+#             */
/*   Updated: 2023/11/23 14:45:13 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	std::string action;
	phonebook prova;
	
	prova.status = 0;
	while (prova.status == 0)
	{
		std::cout << "What do you wanna do? ";
		std::cin >> action;
		if (action == "add")
			prova.add(&prova);
		else if (action == "search")
			prova.search(&prova);
		else if (action == "exit")
			prova.exit(&prova);
	}
	return (0);
}