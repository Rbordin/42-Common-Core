/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:02:20 by rbordin           #+#    #+#             */
/*   Updated: 2023/11/30 14:05:35 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int _fixedp;
        static const int _bits_nbr = 8;
    
    public:
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed& cpy);
        Fixed& operator=(const Fixed& cpy);
        ~Fixed();
        int                 getRawBits(void) const;
        void                setRawBits(int const raw);
        int                 toInt(void) const;
        float				toFloat(void) const;
	    bool                operator>(const Fixed &compare)const;
        bool                operator<(const Fixed &compare)const;
        bool                operator>=(const Fixed &compare)const;
        bool                operator<=(const Fixed &compare)const;
        bool                operator==(const Fixed &compare)const;
        bool                operator!=(const Fixed &compare)const;
        Fixed               operator+(const Fixed &add)const;  
        Fixed               operator-(const Fixed &sub)const;   
        Fixed               operator*(const Fixed &molt)const;   
        Fixed               operator/(const Fixed &div)const;   
        Fixed				&operator++(void);
        Fixed				operator++(int);
        Fixed				&operator--(void);
        Fixed				operator--(int);
        Fixed               &min(Fixed &x, Fixed &y);
        Fixed               &max(Fixed &x, Fixed &y);
        static const Fixed  &min(const Fixed &x, const Fixed &y);
        static const Fixed  &max(const Fixed &x, const Fixed &y);               

};

std::ostream &operator<<(std::ostream &os, const Fixed &nbr);

#endif 