/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:28:04 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 11:37:22 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
{
	std::cout << "A new unknown animal entered the farm" << std::endl;
	this->type = "unknown";
}

Animal::Animal(const Animal &toCopy)
{
	*this = toCopy;
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

Animal	&Animal::operator=(const Animal &toCopy)
{
	this->type = toCopy.type;
	return (*this);
}

