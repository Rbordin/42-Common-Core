/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:56:22 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 11:41:29 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

weapon:: weapon(std::string t)
: type(t)
{
}

weapon:: ~weapon()
{
	;
}

void weapon:: set_type(std::string name)
{
	this->type = name;
}

const std::string &weapon::get_type()
{
	return (this->type);
}