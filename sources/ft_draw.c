#include "tools.h"

t_draw	*ft_init_draw_function(t_draw *draw, t_map *map,
		      unsigned int incx, unsigned int incy)
{
  int x1;
  int x2;
  int y1;
  int y2;

  y1 = HEIGHT * 20 / 100 + ((map->line - 1) * incy);
  y2 = map->line - 1;
  while (y2 >= 0)
    {
      x1 = WIDTH * 2 / 100 + ((map->line - 1 - y2) * incx);
      x2 = -1;
      while (++x2 < map->column)
	{
	  draw->tab[y2][x2].x = x1;
	  draw->tab[y2][x2].y = y1 - (map->tab[y2][x2] * draw->incup);
	  x1 = x1 + incx;
	}
      y1 = y1 - incy;
      y2 = y2 - 1;
    }
  return (draw);
}

void	ft_draw_image(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	aff_line_croi(t_mlx *mlx, t_position *pos1, t_position *d, t_position *inc)
{
  int	inc1;
  int	inc2;
  int	e;
  unsigned int	n;
  int	cl;

  n = 0;
  cl = 0x000000FF;
  mlx_pixel_put(mlx->mlx, mlx->win, pos1->x, pos1->y, cl);
  e = 2 * d->y - d->x;
  inc1 = 2 * (d->y - d->x);
  inc2 = 2 * d->y;
  while (n < d->x)
    {
      if (e >= 0)
	{
	  pos1->y = pos1->y + inc->y;
	  e = e + inc1;
	}
      else
	e = e + inc2;
      pos1->x = pos1->x + inc->x;
      mlx_pixel_put(mlx->mlx, mlx->win, pos1->x, pos1->y, cl);
      n = n + 1;
    }
}

void	aff_line_decroi(t_mlx *mlx, t_position *pos1, t_position *d, t_position *inc)
{
unsigned int	n;
  int	inc1;
  int	inc2;
  int	e;
  int	cl;

  n = 0;
  cl = 0x000000FF;
  mlx_pixel_put(mlx->mlx, mlx->win, pos1->x, pos1->y, cl);
  e = 2 * d->x - d->y;
  inc1 = 2 * (d->x - d->y);
  inc2 = 2 * d->x;
  while (n < d->y)
    {
      if (e >= 0)
	{
	  pos1->x = pos1->x + inc->x;
	  e = e + inc1;
	}
      else
	e = e + inc2;
      pos1->y = pos1->y + inc->y;
      mlx_pixel_put(mlx->mlx, mlx->win, pos1->x, pos1->y, cl);
      n = n + 1;
    }
}

int	aff_line(t_mlx *mlx, t_position pos1, t_position pos2)
{
  t_position	*d;
  t_position	*inc;

  if ((d = malloc(sizeof(t_position))) == NULL)
    return (-1);
  if ((inc = malloc(sizeof(t_position))) == NULL)
    return (-1);
  d->x = ft_abs(pos2.x - pos1.x);
  d->y = ft_abs(pos2.y - pos1.y);
  inc->x = 1;
  inc->y = 1;
  if (pos2.x < pos1.x)
    inc->x = -1;
  if (pos2.y < pos1.y)
    inc->y = -1;
  if (d->x > d->y)
    aff_line_croi(mlx, &pos1, d, inc);
  else
    aff_line_decroi(mlx, &pos1, d, inc);
  return (0);
}
