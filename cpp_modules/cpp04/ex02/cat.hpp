/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:41:10 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:32:29 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "animal.hpp"
# include "brain.hpp"

class Cat : public Animal
{
	private:
		Brain t;
	public:
		Cat();
		Cat(const Cat &toCopy);
		~Cat();
		void	makeSound() const;
		Cat		&operator=(const Cat &rhs);
};

#endif