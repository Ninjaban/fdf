#include "tools.h"

int	ft_fdf_horizon(t_map *map, t_mlx *mlx, t_draw *draw)
{
  int	x;
  int	y;

  y = 0;
  while (y < map->line)
    {
      x = -1;
      while (++x < map->column - 1)
	if (aff_line(mlx, draw->tab[y][x], draw->tab[y][x + 1]) == 1)
	  return (-1);
      y = y + 1;
    }
  return (0);
}

int	ft_fdf_vertical(t_map *map, t_mlx *mlx, t_draw *draw)
{
  int	x;
  int	y;

  y = 0;
  while (y < map->line - 1)
    {
      x = -1;
      while (++x < map->column)
	if (aff_line(mlx, draw->tab[y][x], draw->tab[y + 1][x]) == 1)
	  return (-1);
      y = y + 1;
    }
  return (0);
}

int	ft_fdf(t_map *map)
{
  t_mlx *mlx;
  t_draw *draw;

  if ((mlx = ft_init_mlx()) == NULL)
    return (-1);
  if ((draw = ft_init_draw(map)) == NULL)
    return (-1);

  if (ft_fdf_horizon(map, mlx, draw) == -1)
    return (-1);

  if (ft_fdf_vertical(map, mlx, draw) == -1)
    return (-1);
  while (42)
    ;
  //  ft_draw_image(mlx);
  return (0);
}
