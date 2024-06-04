/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:44:41 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 12:27:45 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

zombie::zombie()
{
	;
}

zombie::zombie(std::string input)
	: name(input)
{
	;
}

zombie::~zombie()
{
	std::cout << this->name + " is dead!" << std::endl;
}
std::string	zombie::get_name()
{
	return (this->name);
}


void zombie::setName(std::string x)
{
	this->name = x;
}

void zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
