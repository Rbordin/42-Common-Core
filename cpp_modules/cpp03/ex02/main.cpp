/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:05 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/03 15:31:12 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Clap("Clap");
	ScavTrap	Scav("Scav");
	FragTrap	Frag("Frag");
	Clap.attack("Frag");
	Clap.takeDamage(5);
	Scav.beRepaired(4);
	Scav.guardGate();
	Frag.highFivesGuys();
	return (0);
}
