/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:42:18 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/04 10:33:53 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string x) : ClapTrap()
{
    this->name = x; 
    this->hitPoints = 100; 
    this->energyPoints = 50; 
    this->attackDmg = 20; 
    std::cout << "ScavTrav costructor has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrav destructor has been called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " just entered gate keeper mode!" << std::endl;
}
