/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrongcat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:43:19 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/14 14:56:15 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrongcat")
{
	std::cout << "A new Wrongcat entered the farm" << std::endl;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal("Wrongcat")
{
	*this = toCopy;
}

WrongCat::~WrongCat()
{
	std::cout << "A Wrongcat left the farm" << std::endl;	
	;
}

void	WrongCat::makeSound()
{
	std::cout << this->type + ": " << "Bark bark" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	this->type = rhs.type;
	return (*this);
}