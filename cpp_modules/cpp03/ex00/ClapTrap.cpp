/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:23:13 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/04 10:32:12 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << "A new ClapTrap named " << this->name << " has just been created!" << std::endl;
    }

ClapTrap::~ClapTrap()
{
    std::cout << "All ClapTraps have been destroyed" << std::endl;
}

std::string ClapTrap::getName()
{
    return (this->name);
}

int ClapTrap::getHitPoints()
{
    return (this->hitPoints);
}

int ClapTrap::getEnergyPoints()
{
    return (this->energyPoints);
}

int ClapTrap::getAttackDmg()
{
    return (this->attackDmg);
}

void ClapTrap::setEnergyPoints(int x, int flag)
{
    if (flag == 0)
        this->energyPoints -= x;
    else
        this->energyPoints += x;
}

void ClapTrap::setHitPoints(int x, int flag)
{
    if (flag == 0)
        this->hitPoints -= x;
    else
        this->hitPoints += x;
}

void    ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << this->getName() << " attacks " << target + ", ";
    std::cout << " causing " << this->getAttackDmg() << " points of damage at cost of 1 energy point!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->setHitPoints(amount, 0);
    std::cout << "ClapTrap " << this->getName() << " took " << amount << " of damage after being attacked!" <<std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    this->setHitPoints(amount, 1);
    this->setEnergyPoints(1, 0);
    std::cout << "ClapTrap " << this->getName() << " rapaired itself and gain " << amount << " resistence for next attacks at cost of 1 energy point!" <<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &toCopy)
{
    this->attackDmg = toCopy.attackDmg;
    this->name = toCopy.name;
    this->energyPoints = toCopy.energyPoints;
    this->hitPoints = toCopy.hitPoints;
    return (*this);
}
