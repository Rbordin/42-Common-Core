/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:00:07 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/04 11:52:07 by rbordin          ###   ########.fr       */
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
		Brain(std::string eureka);
		Brain(const Brain &toCopy);
		~Brain();
		std::string *getIdeas();
		std::string getOneIdea(int i);
		void		setIdeas(std::string eureka);
		Brain 		&operator=(const Brain &toCopy);
};

#endif