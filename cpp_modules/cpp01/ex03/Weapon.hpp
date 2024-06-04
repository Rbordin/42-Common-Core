/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:19:28 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/10 11:56:29 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class weapon
{
	private:
		std::string type;
	public:
		void set_type(std::string name);
		const std::string &get_type();
		weapon(std::string t);
		~weapon();
};

#endif