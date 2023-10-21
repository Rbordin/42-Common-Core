/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcats2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:12 by dcologgi          #+#    #+#             */
/*   Updated: 2023/07/14 17:11:00 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	i = 0;
	d = c;
	while (s[i] != '\0' && s[i] != d)
		i++;
	if (s[i] == '\0' && d != '\0')
		return (-1);
	return (i);
}

static int	generate_argument(t_args *cur, char **ret)
{
	int	i;

	if (ret != NULL)
	{
		free(cur->argument);
		cur->argument = NULL;
		i = 1;
		cur->argument = ft_strdup(ret[0]);
		while (ret[i] != NULL)
		{
			cur->argument = ft_strjoin_mini(cur->argument,
					ret[i], FREE, NO_FREE);
			i++;
		}
		return (1);
	}
	return (0);
}

void	wild(t_shell *mini)
{
	t_args	*cur;
	int		i;
	char	**ret;

	i = -1;
	cur = *mini->list;
	ret = NULL;
	while (cur != NULL)
	{
		if (cur->argument != NULL && my_strchr(cur->argument, '*') != -1)
			i = my_strchr(cur->argument, '*');
		if (cur->argument != NULL && i != -1
			&& (apices(cur->argument, '\"', i) == 1
				&& apices(cur->argument, '\'', i) == 1))
		{
			ret = wildone(mini, cur);
			if (generate_argument(cur, ret) == 1)
				free(ret);
		}
		if (cur->next == NULL)
			return ;
		cur = cur->next;
	}
}
