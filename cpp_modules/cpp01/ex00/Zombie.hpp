/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:38:17 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/03 12:16:28 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class zombie
{
	private:
		std::string name;
	public:
		void	announce(void);
		zombie(std::string input);
		~zombie();
		std::string get_name();
};

void randomChump(std::string name);

#endif