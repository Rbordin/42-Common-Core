/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:53:24 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/23 12:08:49 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T				*list;
		unsigned int	dim;
	public:
		Array(): dim(0){};
		Array(unsigned int n):dim(n)
		{
			this->list = new T[this->dim];
		}
		Array(const Array &toCopy)
		{
			this->dim = toCopy.dim;
			this->list = new T[toCopy.dim];
			for (size_t i = 0; i < toCopy.dim; i++)
				this->list[i] = toCopy.list[i];
		}
		~Array(){delete (this->list);};
		Array	&operator=(const Array &equals)
		{
			if (this == &equals)
				return (*this);
			delete (this->list);
			this->dim = equals.dim;
			this->list = new T[this->dim];
			for (size_t i = 0; i < equals.dim; i++)
				this->list[i] = equals.list[i];
			return (*this);
		}
		T	&operator[](unsigned int s) const
		{
			if (s >= this->dim)
				throw OutOfRange();
			return (this->list[s]);
		}
		unsigned int	size() const{return (this->dim);};
		class OutOfRange : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Index bigger than the size of the array");
				}
		};
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, Array<T> const &toPrint)
{
	for (unsigned int i = 0; i < toPrint.size(); ++i)
	{
		if (sizeof(toPrint[0]) == sizeof(char))
			os << toPrint[i];
		else
			os << toPrint[i] << " ";
	}
	return (os);
}
#endif