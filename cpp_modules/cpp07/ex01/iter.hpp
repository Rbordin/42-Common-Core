/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:30:00 by riccardobor       #+#    #+#             */
/*   Updated: 2023/12/18 16:04:49 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, unsigned long len, T (*toDo)(T))
{
	for (unsigned long i = 0; i < len; i++)
		array[i] = toDo(array[i]);
}

template <typename T>
T	toDo(T arg)
{
	return (arg + arg);
}

#endif