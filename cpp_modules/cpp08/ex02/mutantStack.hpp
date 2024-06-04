/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:44 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/25 11:31:36 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include <string>
# include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(){};
		MutantStack(MutantStack const &toCopy)
		{
			this->std::stack<T, Container>(toCopy);
		}
		virtual ~MutantStack(){};
		MutantStack<T, Container>	&operator=(MutantStack const &toCopy)
		{
			if (this != &toCopy)
				*this = std::stack<T, Container>(toCopy);
			return (*this);
		}
		typedef typename Container::iterator iterator;
		iterator	begin()
		{
			return (std::stack<T, Container>::c.begin());
		}
		iterator	end()
		{
			return (std::stack<T, Container>::c.end());
		}
};

#endif