/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:40:18 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:20:34 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string x);
		WrongAnimal(const WrongAnimal &toCopy);
		virtual ~WrongAnimal();
		std::string		getType() const;
		virtual void	makeSound() const;
		WrongAnimal		&operator=(const WrongAnimal &rhs);
};

#endif