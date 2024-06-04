/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:21:20 by rbordin           #+#    #+#             */
/*   Updated: 2023/09/11 15:30:39 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
    : fixedPoint (0)
{
    std::cout << "Default costructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy  costructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int n)
{
    std::cout << "Constant integer costuctor called" << std::endl;
	this->fixedPoint = n << this->fracBits;
    
}

Fixed::Fixed(const float x)
{
    std::cout << "Constant float costructor called" << std::endl;
	this->fixedPoint = roundf(x * (1 << this->fracBits));
}

Fixed::~Fixed()
{
    std::cout << "Default destuctor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw;
}

int     Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->fracBits);
}

float   Fixed::toFloat(void) const
{
	return ((float)(this->getRawBits()) / (1 << fracBits));
}

Fixed	&Fixed::operator=(const Fixed &first)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = first.getRawBits();
    return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed  &n)
{
    stream << n.toFloat();
    return (stream);
}