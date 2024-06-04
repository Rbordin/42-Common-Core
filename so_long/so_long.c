/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:06:33 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/16 16:19:34 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 5 FUNZIONI: main, controllo del formato e hook
int	xclose(void)
{
	exit(0);
	return (0);
}

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		cleaner(vars);
		lv_cleaner(vars);
		exit(0);
	}
	else if (vars->flag == 1)
		move(keycode, vars);
	else if (keycode == 36 && vars->game_status == 2)
	{
		vars->tardis.total_moves += vars->tardis.move_count;
		vars->tardis.move_count = 0;
		if (vars->lv == vars->max_level)
		{
			vars->game_status = 3;
			draw_map(vars);
		}
		else if (vars->lv < vars->max_level)
		{
			vars->lv++;
			vars->game_status = 0;
			mlx_destroy_window(vars->mlx, vars->win);
			cleaner(vars);
			start(vars);
		}
	}
	else if (keycode == 36 && vars->game_status == 3)
	{
		cleaner(vars);
		lv_cleaner(vars);
		exit(0);
	}
	return (0);
}

int	ft_row_count(char *s1)
{
	int	i;
	int	count;

	count = 0 ;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

int	control_format(char	*argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b' && argv[i + 2] != 'e'
		&& argv[i + 3] != 'r' && argv[i + 4] != '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	
	getting_levels(argv[1], &vars);
	vars.lv = 0;
	vars.tardis.move_count = 0;
	vars.game_status = 4;
	if (argc != 2)
	{
		ft_putstr("Error:\nsomething looks wrong, please try again!");
		exit(1);
	}
	start(&vars);
	cleaner(&vars);
	lv_cleaner(&vars);
	return (0);
}

void	getting_levels(char *path, t_vars *vars)
{
	int 			i;
	int				k;
	DIR				*dir;
	char			*cartella;
	struct dirent	*test;
	
	k = 0;
	i = 1;
	cartella = "maps/";
	vars->levels = ft_calloc (6, sizeof(char *));
	if ((dir = opendir(path)) != NULL)
	{
		while ((test = readdir(dir)) != NULL)
		{
			if (i > 2)
			{
				vars->levels[k] = ft_strjoin(cartella, ft_substr(test->d_name, 0, 8), NO_FREE, FREE);
				k++;
			}
			i++;
		}
	}
	vars->max_level = k;
	vars->levels[k] = NULL;
	closedir(dir);
}
