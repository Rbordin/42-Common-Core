/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:28:04 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:19:23 by riccardobor      ###   ########.fr       */
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

void	Animal::makeSound() const
{
	std::cout << this->type + ": " << "i'm like a crocodile, you don't know what my sound is!" << std::endl;
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

Animal::Animal(const Animal &toCopy)
{
	*this = toCopy;
}