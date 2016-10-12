/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 09:10:05 by jcarra            #+#    #+#             */
/*   Updated: 2016/07/28 11:37:35 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_mlx	*ft_init_mlx(void)
{
  t_mlx *mlx;

  if ((mlx = malloc(sizeof(t_mlx))) == NULL)
    return (NULL);
  if (((mlx->mlx = mlx_init()) == NULL) ||
      ((mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf"))
       == NULL) ||
      ((mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)) == NULL))
    {
      free(mlx);
      return (NULL);
    }
  return (mlx);
}

t_draw	*ft_init_draw(t_map *map)
{
  t_draw *draw;
  unsigned int incx;
  unsigned int incy;
  int n;

  n = 0;
  if ((draw = malloc(sizeof(t_draw))) == NULL)
    return (NULL);
  draw->size = map->line * map->column;
  if ((draw->tab = malloc(sizeof(t_position) * map->line)) == NULL)
    return (NULL);
  while (n < map->column)
    if ((draw->tab[n++] = malloc(sizeof(t_position) * map->column)) == NULL)
      return (NULL);
  incx = (WIDTH - (WIDTH * 4 / 100)) / (map->column + map->line - 1);
  incy = (HEIGHT - (HEIGHT * 25 / 100)) / map->line;
  draw->incup = (HEIGHT * 23 / 100) / ft_max(map);
  draw = ft_init_draw_function(draw, map, incx, incy);
  return (draw);
}
