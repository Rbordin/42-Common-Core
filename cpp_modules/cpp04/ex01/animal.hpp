/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:25:11 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:18:04 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(const Animal &toCopy);
		Animal(std::string x);
		virtual ~Animal();
		std::string		getType() const;
		virtual void	makeSound() const;
		Animal			&operator=(const Animal &rhs);
};

#endif