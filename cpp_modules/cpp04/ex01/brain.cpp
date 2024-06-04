/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:04:23 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/15 10:21:14 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"


Brain::Brain()
{
	std::cout << "Brain base constructor has been called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor has been called" << std::endl;
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}
std::string Brain::getOneIdea(int i)
{
	return (this->ideas[i]);
}

void	Brain::setIdeas(std::string eureka)
{
	static int i = 0;
	
	if (i <= 100)
	{
		this->ideas[i] = eureka;
		i++;
	}
	else
		std::cout << "I had more ideas than i can store..." << std::endl;	
}