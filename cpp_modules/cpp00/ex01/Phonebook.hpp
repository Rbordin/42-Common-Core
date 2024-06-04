/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:35:37 by riccardobor       #+#    #+#             */
/*   Updated: 2023/11/23 14:46:19 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class contact
{
	public:
		int id;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;
		std::string	phone_number;
};

class phonebook
{
	public:
		contact	memory[9];
		int	status;
		void add(phonebook *prova);
		void search(phonebook *prova);
		void exit(phonebook *prova);
};


#endif