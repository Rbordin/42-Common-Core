/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:10:46 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/22 15:26:11 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>

void	swap(T &arg1, T &arg2)
{
	T arg3;

	arg3 = arg1;
	arg1 = arg2;
	arg2 = arg3;
}
template<typename T>

T	min(T arg1, T arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template<typename T>
T max(T arg1, T arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}
#endif