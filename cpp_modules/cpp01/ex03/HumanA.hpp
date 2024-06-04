/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:24:53 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 11:24:05 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class human_a
{
	private:
		std::string name;
		weapon &test;
	public:
		human_a(std::string x, weapon &type);
		~human_a();
		void attack();
		std::string get_name();
};

#endif