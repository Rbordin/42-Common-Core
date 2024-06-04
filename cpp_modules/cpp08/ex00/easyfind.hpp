/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:55:36 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/23 13:12:01 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <iostream>

template<typename T>
void	easyfind(T &container, int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) != container.end())
		std::cout << toFind << " it's present" << std::endl;
	else
		std::cout << toFind << " it's nowhere to find" << std::endl;
}

#endif