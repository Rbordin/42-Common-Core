/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:35:08 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:16:40 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() :Animal()
{
	std::cout << "A new dog entered the farm" << std::endl;
	this->type = "dog";
}

Dog::~Dog()
{
	std::cout << "A dog left the farm" << std::endl;
	;
}

void	Dog::makeSound()
{
	std::cout << this->type + ": " << "Bark bark!" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Dog::Dog(const Dog &toCopy)
{
	*this = toCopy;
}
