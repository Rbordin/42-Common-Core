/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:52 by riccardobor       #+#    #+#             */
/*   Updated: 2023/05/16 15:43:58 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 5 FUNZIONI: applicano gli sprites ai relativi valori

int	draw_map(t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	if (!vars->map)
		return (0);
	if (vars->lv <= vars->max_level)
	{
		mlx_clear_window(vars->mlx, vars->win);
		while (y < vars->i)
		{
			x = 0;
			while (x < vars->width / 64)
			{
				char_definer(vars, y, x);
				x++;
			}
			y++;
			info_display(vars);
		}
		if (vars->game_status == 2 || vars->game_status == 3)
			winning_strings(vars);
	}
	return (0);
}

void	winning_strings(t_vars *vars)
{
	char	*str;
	char	*str2;
	char	*str3;
	
	str = "your tardis succesfully crossed the wormhole!";
	str2 = "get ready for another amazing adventure!";
	str3 = "press enter for next level";
	if (vars->game_status == 3)
	{
		str = "Doc's adventures are over for the moment";
		str2 = "You did an amzing job";
		str3 = "you better get ready for the next amazing adventure!";
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2, 0x00FF0000, str);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2 + 20, 0x00FF0000, str2);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2 + 40, 0x00FF0000, str3);
		vars->flag = 0;
	}
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2, 0x00FF0000, str);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2 + 20, 0x00FF0000, str2);
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 350,
			vars->height / 2 + 40, 0x00FF0000, str3);
	}
}

void	char_definer(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'C' || vars->map[y][x] == 'E')
		draw_e_and_c(vars, x, y);
	else if (vars->map[y][x] == '1' || vars->map[y][x] == '0')
		draw_1_and_0(vars, x, y);
	else if (vars->map[y][x] == 'D' || vars->map[y][x] == 'S')
		draw_d(vars, x, y);
	else if (vars->map[y][x] == 'P' || vars->map[y][x] == 'X')
		draw_p_and_x(vars, x, y);
}

void	win(t_vars *vars)
{
	vars->game_status = 2;
	if (vars->lv == vars->max_level - 1)
		vars->game_status = 3;
	draw_map(vars);
	vars->flag = 0;
}
