/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:43:36 by riccardobor       #+#    #+#             */
/*   Updated: 2023/05/16 16:20:04 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death(t_vars *vars, int y, int x, int keycode)
{
	mlx_destroy_image(vars->mlx, vars->tardis.ship);
	vars->tardis.ship = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/upper_tardis.xpm", &x, &y);
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125)
		vertical_death(vars, keycode);
	if (keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
		horizontal_death(vars, keycode);
	draw_map(vars);
	vars->flag = 2;
	vars->lv = -1;
}

int	start(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->flag = 1;
	vars->enemy_loop = 0;
	vars->enemy_stage = 0;
	vars->steps = 0;
	vars->s1 = NULL;
	vars->enemy.e_stance = 0;
	if (control_format(vars->levels[vars->lv]) == 1)
	{
		ft_putstr("error\nplease give me an actual map\n");
		exit (1);
	}
	map_generator(vars, vars->levels[vars->lv]);
	vars->i = ft_row_count(vars->s1);
	vars->height = vars->i * 64 ;
	vars->width = ft_strlen(vars->map[0]) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->width,
			vars->height + 64, "Tardis adventures");
	if (ft_control(vars) == 0)
	{
		ft_putstr("no map\n");
		exit (1);
	}
	free(vars->s1);
	get_sprites(vars);
	draw_map(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_close, vars);
	mlx_hook(vars->win, 17, 0, xclose, vars);
	mlx_loop_hook(vars->mlx, animation, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void	ft_putstr(char *s1)
{
	if (!s1)
		return ;
	write(1, s1, ft_strlen(s1));
}

void	map_generator(t_vars *vars, char *argv)
{
	vars->fd = open(argv, O_RDONLY);
	if (vars->fd < 0)
	{
		ft_putstr("error\nsomething went wrong\n");
		exit (1);
	}
	vars->pd = get_next_line(vars->fd);
	while (vars->pd != NULL)
	{
		vars->s1 = ft_strjoin(vars->s1, vars->pd, FREE, FREE);
		vars->pd = get_next_line(vars->fd);
		if (!vars->pd)
			break ;
	}
	vars->map = ft_split(vars->s1, '\n');
	close(vars->fd);
	free(vars->pd);
}

void	cleaner(t_vars *vars)
{
	int	x;

	x = 0;
	while (x <= vars->i)
	{
		free(vars->map[x]);
		x++;
	}
	free(vars->map);
}

void	lv_cleaner(t_vars *vars)
{
	int	x;

	x = -1;
	while (vars->levels[++x])
		free(vars->levels[x]);
	free(vars->levels);
}
