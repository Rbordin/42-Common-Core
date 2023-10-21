/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:07:12 by riccardobor       #+#    #+#             */
/*   Updated: 2023/07/13 16:42:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	checking_node_vilidity(t_shell *mini)
{
	t_args	*new;
	t_args	*red;

	red = malloc(sizeof(t_args));
	new = malloc(sizeof(t_args));
	if ((*mini->high)->redirect != NULL)
	{
		new->next = (*mini->high)->next;
		(*mini->high)->next = red;
		red->next = new;
		red->previous = (*mini->high);
		new->previous = red;
		redirecting_nodes(mini, new, red);
		mini->command_presence = 0;
		analizer(mini, NULL);
		return ;
	}
	else
	{
		free(red);
		free(new);
	}
}

int	reassembling_strings(t_shell *mini, char **temp, int i)
{
	int	j;

	j = i;
	while (temp[j] && (temp[j][ft_strlen(temp[j]) - 1] != temp[i][0]))
	{
		if ((*mini->high)->argument == NULL)
			(*mini->high)->argument = ft_strdup(temp[j]);
		else
			(*mini->high)->argument = ft_strjoin_mini((*mini->high)->argument,
					temp[j], FREE, NO_FREE);
		j++;
	}
	if (temp[j] && (temp[j][ft_strlen(temp[j]) - 1] == temp[i][0]))
	{
		if ((*mini->high)->argument == NULL)
			(*mini->high)->argument = ft_strdup(temp[j]);
		else
			(*mini->high)->argument = ft_strjoin_mini((*mini->high)->argument,
					temp[j], FREE, NO_FREE);
	}
	return (j);
}

void	ultimating_commands(t_shell *mini)
{
	t_args	*cur;
	int		k;

	k = 0;
	cur = *mini->list;
	while (cur)
	{
		cur->order = k;
		if (cur->redirect && (ft_strcmp(cur->redirect, "||") == 0
				|| ft_strcmp(cur->redirect, "&&") == 0))
		{
			k++;
			cur->order = k;
			k++;
		}
		if (cur->command && cur->command[0] != '/'
			&& check_builtin_presence(mini, cur->command) != 0)
		{
			cur->command = check_path(mini, cur->command);
		}
		cur = cur->next;
	}
}

void	its_a_command(t_shell *mini, char *temp)
{
	if (mini->command_presence == 0 && (*mini->high)->command == NULL
		&& mini->flags.minor == 0 && mini->flags.redirect_input == 0)
	{
		mini->command_presence = 1;
		(*mini->high)->command = ft_strdup(temp);
	}
	else
	{
		if ((*mini->high)->argument != NULL)
			(*mini->high)->argument = ft_strjoin_mini((*mini->high)->argument,
					temp, NO_FREE, NO_FREE);
		else
			(*mini->high)->argument = ft_strdup(temp);
	}
}
