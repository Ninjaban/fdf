/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:38:52 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:50:14 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	ft_fdf_horizon(t_map *map, t_mlx **mlx, t_draw *draw)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->line)
	{
		x = 0;
		while (x < map->column - 1)
		{
			if (aff_line(&(*mlx), draw->tab[y][x], draw->tab[y][x + 1]) == 1)
				return (-1);
			x = x + 1;
		}
		y = y + 1;
	}
	return (0);
}

static int	ft_fdf_vertical(t_map *map, t_mlx **mlx, t_draw *draw)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->line - 1)
	{
		x = 0;
		while (x < map->column)
		{
			if (aff_line(&(*mlx), draw->tab[y][x], draw->tab[y + 1][x]) == 1)
				return (-1);
			x = x + 1;
		}
		y = y + 1;
	}
	return (0);
}

int			ft_loop_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int			ft_hook(int key)
{
	if (key == 65307)
		exit(0);
	return (0);
}

int			ft_fdf(t_map *map)
{
	t_mlx	*mlx;
	t_draw	*draw;

	if ((mlx = ft_init_mlx()) == NULL)
		return (-1);
	if ((draw = ft_init_draw(map)) == NULL)
		return (-1);
	if (ft_fdf_horizon(map, &mlx, draw) == -1)
		return (-1);
	if (ft_fdf_vertical(map, &mlx, draw) == -1)
		return (-1);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 3, &ft_hook, NULL);
	mlx_loop(mlx->mlx);
	return (0);
}
