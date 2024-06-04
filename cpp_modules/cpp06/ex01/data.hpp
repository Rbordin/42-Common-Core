/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:30:39 by riccardobor       #+#    #+#             */
/*   Updated: 2023/09/22 09:20:19 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int	data;
	public:
		Data();
		Data(int x): data(x) {};
		~Data(){;};
		int		getData() {return (data);};
		void	setData(int x) {this->data = x;};
};

#endif