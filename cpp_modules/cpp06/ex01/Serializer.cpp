/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:35:44 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 15:44:50 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "constructor called" << std::endl;
}
Serializer::~Serializer()
{
	std::cout << "distructor called" << std::endl;
}
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}
Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data*>(raw));
}