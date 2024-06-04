/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wronganimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:44:56 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:20:22 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "A new unknown wronganimal entered the farm" << std::endl;
	this->type = "unknown";
}

WrongAnimal::WrongAnimal(std::string x)
{
	std::cout << "A new unknown wronganimal entered the farm" << std::endl;
	this->type = x;
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	*this = toCopy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "A unknown wronganimal left the farm" << std::endl;
	;
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->type + ": " << "i'm like a crocodile, you don't know what my sound is!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

