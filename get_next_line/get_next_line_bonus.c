/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:43:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/06/25 16:19:19 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_finder(char *mem)
{
	size_t	i;

	if (!mem)
		return (NULL);
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			return (mem + i);
		i++;
	}
	return (NULL);
}

char	*ft_link(char *mem, char *tmp)
{
	int		i;
	int		j;
	char	*clear;

	if (!mem && (!tmp || !*tmp))
		return (NULL);
	i = 0;
	if (mem)
	{
		while (mem[i])
			++i;
	}
	j = 0;
	while (tmp[j])
		++j;
	clear = (char *)malloc(sizeof(char) * i + j + 1);
	if (!clear)
		return (NULL);
	clear[i + j] = '\0';
	while (--j >= 0)
		clear[i + j] = tmp[j];
	while (--i >= 0)
		clear[i] = mem[i];
	free(mem);
	return (clear);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	**mem;

	mem = malloc(4096 * sizeof(char *));
	if (!mem)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem[fd] = place_holder(fd, mem[fd]);
	if (!mem[fd] || !*mem[fd])
	{
		free(mem[fd]);
		return (NULL);
	}
	res = extract(mem[fd]);
	mem[fd] = forget(mem[fd]);
	return (res);
}
