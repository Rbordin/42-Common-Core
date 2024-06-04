/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:43:19 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 11:30:21 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "A new cat entered the farm" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A cat left the farm" << std::endl;	
	;
}

void	Cat::makeSound() const
{
	std::cout << this->type + ": " << "Meow meow, prrrrrrr..." << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	this->type = rhs.type;
	return (*this);
}