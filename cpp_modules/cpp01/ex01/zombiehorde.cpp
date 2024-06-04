/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:00:34 by rbordin           #+#    #+#             */
/*   Updated: 2023/10/03 12:23:45 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

zombie *zombieHorde(int n, std::string name)
{
	zombie *horde = new zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}
