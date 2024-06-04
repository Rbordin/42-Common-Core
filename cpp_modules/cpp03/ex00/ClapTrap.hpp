/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:15:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/03 15:37:46 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class   ClapTrap
{
	private:
		std::string name;
		int         hitPoints;
		int         energyPoints;
		int         attackDmg;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		std::string	getName();
		int			getHitPoints();
		int			getEnergyPoints();
		int			getAttackDmg();
		void		setEnergyPoints(int x, int flag);
		void		setHitPoints(int x, int flag);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		ClapTrap    &operator=(const ClapTrap &toCopy);
};

#endif