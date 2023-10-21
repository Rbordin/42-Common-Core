/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:56:28 by rbordin           #+#    #+#             */
/*   Updated: 2023/07/17 13:37:19 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operator_checker(const char *s, char control)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == control)
		{
			if (s[i + 1] == control && s[i - 1] != '\\')
			{
				if ((apices(s, '\"', i) == 0)
					|| (apices(s, '\'', i) == 0))
					return (0);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
