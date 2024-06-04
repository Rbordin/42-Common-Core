/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:20 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 11:30:39 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include "animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &toCopy);
		~Dog();
		void makeSound() const;
		Dog	&operator=(const Dog &rhs);

};
#endif