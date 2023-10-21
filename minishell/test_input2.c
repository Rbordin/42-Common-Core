/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:19:38 by gpecci            #+#    #+#             */
/*   Updated: 2023/07/14 17:11:00 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_delimiter(char c, char *str, int i)
{
	return (c == '|' || c == '&');
}

char	*getting_final_string(char *s, char c)
{
	t_varie	*var;

	var = ft_calloc(1, sizeof(t_varie));
	init_varie(var, 0);
	var->i = 0;
	var->newstr = ft_calloc(ft_strlen(s) + counting(s) + 1, sizeof(char));
	while (s[var->i])
	{
		if ((s[var->i] == c && c != '<' && c != '>') && s[var->i + 1] == ' ')
			first_half(var, s, c);
		else if ((s[var->i] == '<' || s[var->i] == '>')
			&& s[var->i + 1] != ' ')
			sencond_half(var, s, c);
		var->newstr[var->z] = s[var->i];
		var->i++;
		var->z++;
	}
	var->newstr[var->z] = '\0';
	free(s);
	return (var->newstr);
}

int	counting(char *s)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '|' || s[i] == '&' || s[i] == '<' || s[i] == '>')
		{
			if (apices(s, s[i], i))
				k++;
		}
		i++;
	}
	return (k);
}

int	start(t_shell *mini)
{
	int	len;

	mini->input = ft_strtrim(mini->input, " ");
	len = strlen(mini->input);
	if (len == 0 || !mini->input)
		return (0);
	if (len > 0 && mini->input[len - 1] == '\n')
	{
		mini->input[len - 1] = '\0';
		len--;
	}
	mini->input = insert_spaces(mini->input, len);
	mini->input = getting_final_string(mini->input, '|');
	mini->input = getting_final_string(mini->input, '&');
	mini->input = getting_final_string(mini->input, '<');
	mini->input = getting_final_string(mini->input, '>');
	return (1);
}

void	init_varie(t_varie *varie, int len)
{
	varie->i = -1;
	varie->j = 0;
	varie->z = 0;
	varie->newlen = len;
	varie->withinquotes = 0;
	varie->withindoublequotes = 0;
	varie->quotesstack = 0;
	varie->doublequotesstack = 0;
}
