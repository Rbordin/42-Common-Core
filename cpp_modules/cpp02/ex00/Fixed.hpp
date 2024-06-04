/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:10:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/09/11 13:59:19 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed(Fixed &copy);
		~Fixed();
		int		getRawBits(void);
		void	setRawBits(int const raw);
		Fixed	&operator=(Fixed &first);

};

#endif