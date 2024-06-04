/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:20 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:32:51 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include "animal.hpp"
# include "brain.hpp"

class Dog : public Animal
{
	private:
		Brain t;
	public:
		Dog();
		Dog(const Dog &toCopy);
		~Dog();
		void	makeSound() const;
		Dog		&operator=(const Dog &rhs);

};
#endif