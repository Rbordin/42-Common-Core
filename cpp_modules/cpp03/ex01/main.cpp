/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:05 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/03 15:37:46 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Gigino("gigino");
	ScavTrap	Gigetto("gigetto");
	ClapTrap	Gigiotto("gigiotto");
	
	Gigino.attack("Gigetto");
	Gigetto.attack("Gigiotto");
	Gigiotto.beRepaired(10);
	Gigino.guardGate();
	Gigiotto.attack("Gigino");
	Gigino.takeDamage(0);
	return (0);
}
