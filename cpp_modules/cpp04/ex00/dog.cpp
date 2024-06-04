/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:35:08 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 11:30:56 by rbordin          ###   ########.fr       */
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
}

void	Dog::makeSound() const
{
	std::cout << this->type + ": " << "Bark bark!" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return (*this);
}