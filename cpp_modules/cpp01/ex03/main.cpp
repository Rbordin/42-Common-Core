/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:04:34 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 11:34:23 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		weapon club = weapon("crude spiked club");
		human_a bob("Bob", club);
		bob.attack();
		club.set_type("some other type of club");
		bob.attack();
	}
	{
		weapon club = weapon("crude spiked club");
		human_b jim("Jim");
		jim.set_weapon(club);
		jim.attack();
		club.set_type("some other type of club");
		jim.attack();
	}
	return 0;
}
