/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:00:07 by riccardobor       #+#    #+#             */
/*   Updated: 2023/10/06 09:24:31 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain &toCopy);
		~Brain();
		std::string *getIdeas();
		std::string getOneIdea(int i);
		void		setIdeas(std::string eureka);
		Brain		&operator=(const Brain &toCopy);
};

#endif