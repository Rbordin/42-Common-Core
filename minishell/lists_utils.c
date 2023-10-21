/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:58:33 by riccardobor       #+#    #+#             */
/*   Updated: 2023/07/12 15:46:53 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test(t_shell *mini, t_args *new_node)
{
	t_args	*last;

	last = *mini->list;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->previous = last;
	new_node->next = NULL;
	*mini->high = new_node;
}

void	clear_list(t_shell *mini)
{
	t_args	*current;

	current = (*mini->list);
	while ((*mini->list) != NULL)
	{
		if (current->str != NULL)
			free((*mini->list)->str);
		if (current->command != NULL)
			free((*mini->list)->command);
		if (current->flags != NULL)
			free((*mini->list)->flags);
		if (current->argument != NULL)
			free((*mini->list)->argument);
		if (current->redirect != NULL)
			free((*mini->list)->redirect);
		current = (*mini->list)->next;
		(*mini->list) = (*mini->list)->next;
	}
	free(mini->list);
	(mini->list) = NULL;
	free(mini->high);
	(mini->high) = NULL;
}

void	init_node(t_args *node)
{
	node->command = NULL;
	node->flags = NULL;
	node->argument = NULL;
	node->redirect = NULL;
	node->str = NULL;
	node->infile = NULL;
	node->outfile = NULL;
	node->redirection_quantity = 0;
}
