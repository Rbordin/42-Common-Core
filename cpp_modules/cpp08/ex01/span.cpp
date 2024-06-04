/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:18:07 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/23 17:35:06 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
	;
}
Span::Span(unsigned int n)
{
	this->dim = n;
}
Span::~Span()
{
	;	
}

std::list<int> Span::getList() const
{
	return (this->list);
}

void	Span::addNumber(int toAdd)
{
	try
	{
		if (this->list.size() > this->dim)
		{
			throw (noRoomException());
		}
	}
	catch (noRoomException &e)
	{
		std::cerr << e.what() <<std::endl;
	}
	this->list.push_back(toAdd);
	return ;	
}

int	Span::longestSpan()
{
	try
	{
		if (this->dim <= 1)
			throw (notEnoughNumb());

	}
	catch (notEnoughNumb &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
		return (*std::max_element(this->list.begin(), this->list.end())) - *std::min_element(this->list.begin(), this->list.end());
}
int	Span::shortestSpan()
{
	int	i = this->longestSpan();
	try
	{
		if (this->dim <= 1)
			throw (notEnoughNumb());

	}
	catch (notEnoughNumb &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}	
	std::list<int>::iterator it;
	for (it = this->list.begin(); it != this->list.end(); ++it)
	{
		std::list<int>::iterator it2;
		for (it2 = this->list.begin(); it2 != this->list.end(); ++it2)
		{
			if (*it == *it2)
				continue;
			if ((*it - *it2 < i) && (*it - *it2 > 0))
				i = (*it - *it2);	
		}
	}
	return (i);
}

std::ostream	&operator<<(std::ostream &out, Span const &list)
{
	std::list<int>::const_iterator it;
	for (it = list.getList().begin(); it != list.getList().end(); ++it)
	{
		out << *it << " ";
	}
	out << std::endl;
	return (out);
}