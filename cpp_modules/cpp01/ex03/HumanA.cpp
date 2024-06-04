/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:09:00 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 12:07:13 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

human_a::human_a(std::string x, weapon &type)
	: name(x), test(type)
{
	;
}

human_a:: ~human_a()
{
	;
}

void human_a::attack()
{
	std::cout << this->get_name() << " attacks with their " << this->test.get_type() << std::endl;
}

std::string human_a::get_name()
{
	return (name);
}