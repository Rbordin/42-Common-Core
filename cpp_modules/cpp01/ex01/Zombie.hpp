/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:38:17 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 12:26:21 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <vector>

class zombie
{
	private:
		std::string name;
	public:
		zombie();
		zombie(std::string input);
		~zombie();
		void	announce(void);
		std::string get_name();
		void	setName(std::string x);
};

#endif