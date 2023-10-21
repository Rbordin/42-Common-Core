/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:12:59 by dcologgi          #+#    #+#             */
/*   Updated: 2023/07/18 10:44:04 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	handlectrl(t_shell *mini, char **envp)
{
	char	input[256];

	if (!mini->input)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
}

void	handlectrlc(int signal)
{
	write(1, "\n", 1);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
