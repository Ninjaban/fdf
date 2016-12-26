/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:00 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:49:43 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		ft_init_draw_function(t_draw **draw, t_map *map,
									unsigned int incx, unsigned int incy)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	y1 = HEIGHT * 20 / 100 + ((map->line - 1) * incy);
	y2 = map->line - 1;
	while (y2 >= 0)
	{
		x1 = WIDTH * 2 / 100 + ((map->line - 1 - y2) * incx);
		x2 = -1;
		while (++x2 < (int)map->column)
		{
			(*draw)->tab[y2][x2].x = x1;
			(*draw)->tab[y2][x2].y = y1 - (map->tab[y2][x2] * (*draw)->incup);
			x1 = x1 + incx;
		}
		y1 = y1 - incy;
		y2 = y2 - 1;
	}
}

static void	ft_init_px(t_mlx **mlx, t_position *pos1)
{
	if (pos1->x < WIDTH && pos1->y < HEIGHT)
	{
		(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = 0;
		(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = 0;
		(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = 0xFF;
	}
}

static void	aff_line_croi(t_mlx **mlx, t_position *pos1, t_position *d,
						t_position *inc)
{
	unsigned int	n;
	int				inc1;
	int				inc2;
	int				e;

	n = 0;
	ft_init_px(&(*mlx), pos1);
	e = 2 * (*d).y - (*d).x;
	inc1 = 2 * ((*d).y - (*d).x);
	inc2 = 2 * (*d).y;
	while (n < (*d).x)
	{
		if (e >= 0)
		{
			pos1->y = pos1->y + (*inc).y;
			e = e + inc1;
		}
		else
			e = e + inc2;
		pos1->x = pos1->x + (*inc).x;
		ft_init_px(&(*mlx), pos1);
		n = n + 1;
	}
}

static void	aff_line_decroi(t_mlx **mlx, t_position *pos1, t_position *d,
							t_position *inc)
{
	unsigned int	n;
	int				inc1;
	int				inc2;
	int				e;

	n = 0;
	ft_init_px(&(*mlx), pos1);
	e = 2 * (*d).x - (*d).y;
	inc1 = 2 * ((*d).x - (*d).y);
	inc2 = 2 * (*d).x;
	while (n < (*d).y)
	{
		if (e >= 0)
		{
			pos1->x = pos1->x + (*inc).x;
			e = e + inc1;
		}
		else
			e = e + inc2;
		pos1->y = pos1->y + (*inc).y;
		ft_init_px(&(*mlx), pos1);
		n = n + 1;
	}
}

int			aff_line(t_mlx **mlx, t_position pos1, t_position pos2)
{
	t_position	d;
	t_position	inc;

	d.x = ft_abs(pos2.x - pos1.x);
	d.y = ft_abs(pos2.y - pos1.y);
	inc.x = 1;
	inc.y = 1;
	if (pos2.x < pos1.x)
		inc.x = -1;
	if (pos2.y < pos1.y)
		inc.y = -1;
	if (d.x > d.y)
		aff_line_croi(&(*mlx), &pos1, &d, &inc);
	else
		aff_line_decroi(&(*mlx), &pos1, &d, &inc);
	return (0);
}
