/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:21:20 by rbordin           #+#    #+#             */
/*   Updated: 2023/09/11 13:59:09 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
    : fixedPoint (0)
{
    std::cout << "Default costructor called" << std::endl;
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy  costructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Default destuctor called" << std::endl;
}

int		Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw;
}

Fixed	&Fixed::operator=(Fixed &first)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = first.getRawBits();
}
