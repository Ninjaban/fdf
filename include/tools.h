/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:42:29 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:29:57 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define FALSE 0
# define TRUE 1
# define WIDTH 1920
# define HEIGHT 1080

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_position
{
	size_t			x;
	size_t			y;
}				t_position;

typedef struct	s_map
{
  int				**tab;
  size_t			line;
  size_t			column;
}				t_map;

typedef struct	s_draw
{
  t_position		**tab;
  unsigned int		size;
  unsigned int		incup;
}				t_draw;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*val;
}				t_mlx;

void			ft_draw_image(t_mlx *mlx);
void			ft_init_draw_function(t_draw **draw, t_map *map,
			       unsigned int incx, unsigned int incy);
int				ft_open(char *name);
int				ft_parsing(char *str);
int				ft_fdf(t_map *map);
int				ft_abs(int n);
int				ft_max(t_map *map);
int				ft_min(t_map *map);
int				ft_atoi_spe(char *str, int n);
int				ft_around(unsigned int a, unsigned int b);
int				aff_line(t_mlx **mlx, t_position pos1, t_position pos2);
t_mlx			*ft_init_mlx(void);
t_draw			*ft_init_draw(t_map *map);

#endif
