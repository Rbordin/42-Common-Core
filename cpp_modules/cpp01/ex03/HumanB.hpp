/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:34:17 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 12:05:20 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class human_b
{
	private:
		std::string name;
		weapon *arm;
	public:
		void set_weapon(weapon &type);
		void attack();
		human_b(std::string x);
		~human_b();
};

#endif