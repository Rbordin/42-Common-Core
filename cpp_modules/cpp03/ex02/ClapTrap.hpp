/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:15:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/04 10:33:20 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class   ClapTrap
{
    protected:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDmg;
   
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        std::string getName();
        int         getHitPoints();
        int         getEnergyPoints();
        int         getAttackDmg();
        void        setEnergyPoints(int x, int flag);
        void        setHitPoints(int x, int flag);
        void        attack(const std::string &target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif