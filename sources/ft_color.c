/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:40 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/27 14:43:35 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		ft_color_0(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_0R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_0G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_0B;
}

void		ft_color_1(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_1R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_1G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_1B;
}

void		ft_color_2(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_2R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_2G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_2B;
}

void		ft_color_3(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_3R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_3G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_3B;
}

void		ft_color_4(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_4R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_4G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_4B;
}
