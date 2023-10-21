/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:45:37 by rbordin           #+#    #+#             */
/*   Updated: 2023/07/17 13:36:35 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	path_related(t_shell *mini, char *temp, int i)
{
	if (temp[0] == '/' && check_path2(mini, temp) == 1
		&& check_builtin_presence(mini, temp) == 1)
		its_a_command(mini, temp);
	else if (check_path(mini, temp) != NULL
		&& check_builtin_presence(mini, temp) == 1)
		its_a_command(mini, temp);
	else if (check_path(mini, temp) == NULL)
	{
		its_not_a_command(mini, temp, i);
		if (mini->exit == 1)
			return ;
	}
	if (ft_strcmp((*mini->high)->str, "||") == 0
		|| ft_strcmp((*mini->high)->str, "&&") == 0)
	{
		mini->flags.command_separator = 1;
		mini->command_presence = 0;
	}
	if (temp[0] == '$' && (*mini->high)->order == 0 && i == 0)
		mini->dollar_flag = 1;
}

static int	not_path_related(t_shell *mini, char **temp, int i)
{
	if (temp[i][0] == '(')
		i = reassembling_brackets(mini, temp, i);
	else if (temp[i][0] == '-')
	{
		if ((*mini->high)->argument == NULL)
			its_a_flag(mini, temp[i]);
	}
	else if (temp[i][0] == '\'' || temp[i][0] == '\"')
		i = reassembling_strings(mini, temp, i);
	return (i);
}

static void	anal(t_shell *mini, char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (!apices(temp[i], '\'', 1)
			|| !apices(temp[i], '\"', 1))
			(*mini->high)->argument = ft_strdup(temp[i]);
		else if (temp[i][0] == '(' || temp[i][0] == '-'
			|| temp[i][0] == '\'' || temp[i][0] == '\"')
			i = not_path_related(mini, temp, i);
		else if (check_builtin_presence(mini, temp[i]) == 0
			&& (*mini->high)->command == NULL)
			(*mini->high)->command = ft_strdup(temp[i]);
		else
			path_related(mini, temp[i], i);
		i++;
		if (temp[i] == NULL && (*mini->high)->command != NULL)
			checking_node_vilidity(mini);
		if (mini->exit == 1)
			return ;
	}
}

void	analizer(t_shell *mini, char **envp)
{
	int		res;
	char	**temp;

	temp = ft_echo_split(mini, (*mini->high)->str, 32);
	if (!apices((*mini->high)->str, '\'', 1)
		|| !apices((*mini->high)->str, '\"', 1))
		(*mini->high)->argument = ft_strdup((*mini->high)->str);
	else
	{
		anal(mini, temp);
		if ((*mini->high)->command == NULL && (*mini->high)->redirect == NULL)
		{
			mini->flag_status = 127;
			printf("command not found\n");
		}
	}
	free_matrix(temp);
}

int	check_path2(t_shell *mini, char *s)
{
	if (access(s, F_OK) == 0)
		return (1);
	return (0);
}
