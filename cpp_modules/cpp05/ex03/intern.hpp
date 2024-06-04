/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:24:46 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/20 13:35:43 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "allforms.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		AForm	*makeForm(std::string form, std::string target);	
};

#endif