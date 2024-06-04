/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:17:25 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/23 16:39:30 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>

class Span
{
	private:
		std::list<int>	list;
		size_t			dim;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		std::list<int> getList() const;
		void	addNumber(int toAdd);
		int		shortestSpan();
		int		longestSpan();
		class noRoomException : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("this vector is already full");
				}
		};
		class notEnoughNumb : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("there are not enough numbers to find a spawn");
				}
		};

};

std::ostream	&operator<<(std::ostream &out, Span const &list);

#endif