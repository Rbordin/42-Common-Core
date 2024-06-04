/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:59:38 by riccardobor       #+#    #+#             */
/*   Updated: 2023/11/24 10:17:29 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


void phonebook::add(phonebook *prova)
{
	static int	i = 0;
	
	if (i == 9)
		i = 0;
	std::cout << "Insert new contact first name: " << std::endl;
	std::cin >> prova->memory[i].first_name;
	std::cout << "Insert new contact last name: " << std::endl;
	std::cin >> prova->memory[i].last_name;
	std::cout << "Insert new contact nick name: " << std::endl;
	std::cin >> prova->memory[i].nick_name;
	std::cout << "now please insert their darkest secret... but keep it quiet: " << std::endl;
	std::cin >> prova->memory[i].darkest_secret;
	std::cout << "Insert his phone number" << std::endl;
	std::cin >> prova->memory[i].phone_number;
	prova->memory[i].id = i + 1;
	if (memory[i].first_name.empty() || memory[i].last_name.empty() || memory[i].nick_name.empty() || memory[i].darkest_secret.empty() || memory[i].phone_number.empty())
		std::cout << "We're sorry but this new contact can't be added because of lacking informations" << std::endl;
	else
		i++;
}

void	phonebook::search(phonebook *prova)
{
	int j = 0;

	if (prova->memory[0].first_name.empty())
	{
		std::cout << "there's no contact yet" << std::endl;
		return ;
	}
	while (prova->memory[j].id)
	{
		std::cout << prova->memory[j].id << "         |";
		if (prova->memory[j].first_name.size() <= 9)
		{
			std::cout << prova->memory[j].first_name;
			for (int i = 1; i <= (int)(10 - (int)prova->memory[j].first_name.size()); i++)
				std::cout << " ";
			std::cout << "|";
		}
		else
		{
			for (int i = 0; i < 9; i++)
				std::cout << prova->memory[j].first_name[i];
			std::cout << ".|";
		}
		if (prova->memory[j].last_name.size() <= 9)
		{
			std::cout << prova->memory[j].last_name;
			for (int i = 1; i <= (int)(10 - (int)prova->memory[j].last_name.size()); i++)
				std::cout << " ";
			std::cout << "|";
		}
		else
		{
			for (int i = 0; i < 9; i++)
				std::cout << prova->memory[j].last_name[i];
			std::cout << ".|";
		}
		for (int i = 0; i < 9; i++)
				std::cout << prova->memory[j].nick_name[i];
		std::cout << std::endl;
		j++;
	}
	int input;
	std::cout << "what contact do you wanna see?" << std::endl;
	std::cin >> input;
	if (prova->memory[input - 1].id && (input > 0 && input < 9))
	{
		input -= 1;
		std::cout << "id = " << prova->memory[input].id << std::endl;
		std::cout << "fist name = " + prova->memory[input].first_name << std::endl;
		std::cout << "last name = " + prova->memory[input].last_name << std::endl;
		std::cout << "nick name = " + prova->memory[input].nick_name << std::endl;
		std::cout << "secret = " + prova->memory[input].darkest_secret << std::endl;
		std::cout << "number = " + prova->memory[input].phone_number << std::endl;
	}
	else
		std::cout << "ther's no contact at " << input << std::endl;
}

void phonebook::exit(phonebook *prova)
{
	prova->status = 1;
}