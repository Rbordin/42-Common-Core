/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:10:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/09/11 14:50:27 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int n);
		Fixed(const float x);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		Fixed	&operator=(const Fixed &first);
		
};

std::ostream	&operator<<(std::ostream &stream, const Fixed  &n);

#endif