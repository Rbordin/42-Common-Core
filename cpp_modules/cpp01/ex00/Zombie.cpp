/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:50:32 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 12:19:30 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

zombie::zombie(std::string input)
	: name(input)
	{
	}

zombie::~zombie()
{
	std::cout << this->name + " is dead!" << std::endl;
}
std::string	zombie::get_name()
{
	return (this->name);
}