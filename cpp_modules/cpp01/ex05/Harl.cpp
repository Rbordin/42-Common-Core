/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:40:05 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/29 14:22:54 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

harl::harl()
{
	
}

harl::~harl()
{
	;
}

void harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void harl::error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void harl::complain(std::string level)
{
	void (harl::*pointer)(void) = nullptr;
	std::transform(level.begin(), level.end(), level.begin(), ::tolower);
	std::string levels[4] = {"debug", "info", "warning", "error"};
	int j = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			j = i;
			break ;
		}
	}
	switch (j)
	{
		case 0:
			pointer = &harl::debug;
			break;
		case 1:
			pointer = &harl::info;
			break;
		case 2:
			pointer = &harl::warning;
			break;
		case 3:
			pointer = &harl::error;
			break;
		default:
			std::cerr << "level not avaiable" << std::endl;
			return;
	}
	(this->*pointer)();
}