/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:24:26 by riccardobor       #+#    #+#             */
/*   Updated: 2023/07/12 15:48:13 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	checking_args(t_args *cur)
{
	int	i;

	i = 0;
	while (cur->argument)
	{
		if (cur->argument[i] == '\0')
		{
			free(cur->argument);
			cur->argument = NULL;
		}
		else if (cur->argument[i] != ' ')
			break ;
		i++;
	}
}

static void	no_infile_or_outfile(t_args *cur, t_args *red, int k)
{
	if (cur->infile != NULL && ft_strchr(cur->str, '<') != -1)
	{
		cur->argument = ft_strdup(cur->infile);
		if (cur->str[ft_strchr(cur->str, '<') + 1] == '<')
			cur->argument = NULL;
	}
	else if (cur->outfile != NULL && ft_strchr(cur->str, '>') != -1)
	{
		cur->argument = ft_substr(cur->str, ft_strlen(cur->command)
				+ 1, ft_strchr(cur->str, '>') - ft_strlen(cur->command) - 1);
		cur->argument = ft_strtrim(cur->argument, " ");
	}
	else
	{
		cur->argument = ft_substr(cur->str, ft_strlen(cur->command)
				+ k + 1, ft_strchr(cur->str, red->str[0]) - k
				- ft_strlen(cur->command) - 1);
		cur->argument = ft_strtrim(cur->argument, " ");
	}
}

static void	infile_or_outfile(t_args *cur)
{
	if (ft_strchr(cur->str, '|') < ft_strchr(cur->str, '>'))
	{
		cur->outfile = NULL;
		cur->redirection_quantity = 0;
	}
	if (ft_strchr(cur->str, '|') < ft_strchr(cur->str, '<'))
	{
		cur->infile = NULL;
		cur->redirection_quantity = 0;
	}
	if (cur->infile != NULL && cur->outfile != NULL)
	{
		if (ft_strchr(cur->str, '<') < ft_strchr(cur->str, '>'))
			cur->outfile = NULL;
		else
			cur->infile = NULL;
	}
}

void	redirecting_nodes(t_shell *mini, t_args *new, t_args *red)
{
	int	k;

	k = 0;
	if ((*mini->high)->flags != NULL)
		k = ft_strlen((*mini->high)->flags);
	init_node(red);
	init_node(new);
	(*mini->high)->str = ft_strtrim((*mini->high)->str, " ");
	red->str = ft_strdup((*mini->high)->redirect);
	(*mini->high)->redirect = NULL;
	red->redirect = ft_strdup(red->str);
	new->str = ft_substr((*mini->high)->str,
			ft_strchr((*mini->high)->str, red->str[0])
			+ 1, ft_strlen((*mini->high)->str)
			- ft_strchr((*mini->high)->str, red->str[0]));
	infile_or_outfile((*mini->high));
	no_infile_or_outfile((*mini->high), red, k);
	checking_args((*mini->high));
	free((*mini->high)->redirect);
	(*mini->high) = new;
}
