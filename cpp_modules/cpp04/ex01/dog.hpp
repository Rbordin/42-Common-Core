/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:20 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/15 10:44:25 by riccardobor      ###   ########.fr       */
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
		~Dog();
		void makeSound();
		Dog	&operator=(const Dog &rhs);

};
#endif