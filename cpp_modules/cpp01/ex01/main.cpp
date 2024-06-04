/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:57:53 by rbordin           #+#    #+#             */
/*   Updated: 2023/10/03 12:24:50 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

zombie *zombieHorde(int n, std::string name);

int main()
{
	zombie *jack = zombieHorde(5, "jack");
	delete [] jack;
	return (0);
}