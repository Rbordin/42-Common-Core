/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:25:02 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 12:01:26 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

human_b::human_b(std::string x)
: name(x), arm(0)
{
}

human_b:: ~human_b()
{
	;
}

void human_b::attack()
{
	if (this->arm)
		std::cout << this->name << " attacks with their " << this->arm->get_type() << std::endl;
	else
		std::cout << this->name << " attack with his bare hands" << std::endl;
}

void human_b::set_weapon(weapon &type)
{
	this->arm = &type;
}