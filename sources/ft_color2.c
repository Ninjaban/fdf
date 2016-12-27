/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:43:47 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/27 14:43:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void		ft_color_5(t_mlx **mlx, t_position *pos1)
{
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 2] = COLOR_5R;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4) + 1] = COLOR_5G;
	(*mlx)->val[(pos1->x * 4) + (pos1->y * WIDTH * 4)] = COLOR_5B;
}
