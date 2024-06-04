/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:28:04 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/15 12:02:39 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
{
	std::cout << "A new unknown animal entered the farm" << std::endl;
	this->type = "unknown";
}

Animal::Animal(std::string x)
{
	std::cout << "A new unknown animal entered the farm" << std::endl;
	this->type = x;
}

Animal::~Animal()
{
	std::cout << "A unknown animal left the farm" << std::endl;
	;
}

std::string Animal::getType() const
{
	return(this->type);
}

Animal	&Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

