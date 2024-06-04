/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:08:43 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 10:33:44 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "FragTrap";
    this->attackDmg = 30;
    this->hitPoints = 100;
    this->energyPoints = 100;
    std::cout << "FRAGTRAP default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FRAGTRAP destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->name = name;
    this->attackDmg = 30;
    this->hitPoints = 100;
    this->energyPoints = 100;
    std::cout << "FRAGTRAP name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
    *this = toCopy;
}

FragTrap	&FragTrap::operator=(const FragTrap &toCopy)
{
	this->name = toCopy.name;
    this->hitPoints = toCopy.hitPoints;
    this->energyPoints = toCopy.energyPoints;
    this->attackDmg = toCopy.attackDmg;
    std::cout << "Fragtrap assignation operator called" << std::endl;
    return (*this);
}

void		FragTrap::highFivesGuys()
{
    std::cout << this->name << " is asking for high fives" << std::endl;
}

void		FragTrap::attack(const std::string &target)
{
	if (!this->energyPoints)
        return;
    this->energyPoints--;
    std::cout << this->name << " attacks " << target << ", causing " << this->attackDmg << " points of damage! by FRAGTRAP" << std::endl;
}
