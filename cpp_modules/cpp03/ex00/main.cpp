/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:07:18 by rbordin           #+#    #+#             */
/*   Updated: 2023/12/03 15:37:46 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap test("giacomo");
    ClapTrap test2("aldo");

    test.attack("aldo");
    test2.beRepaired(10);
}