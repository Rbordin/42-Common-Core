/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:27:46 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 15:43:14 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>

struct Data
{
	int data;
	int	*ptr;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
		class	notConvertable : public std::exception
		{
			public:
				notConvertable(void) {}
				virtual const char	*what() const throw() {
									return ("Error: input not convertable\n"); }
		};
};

#endif

