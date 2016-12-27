/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:42:29 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/27 12:56:01 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define FALSE 0
# define TRUE 1
# define WIDTH 2560
# define HEIGHT 1440

# define COLOR_R 0xFF
# define COLOR_G 0xFA
# define COLOR_B 0xFA

# define COLOR_5 90
# define COLOR_5R 0x87
# define COLOR_5G 0x48
# define COLOR_5B 0x00

# define COLOR_4 40
# define COLOR_4R 0x1C
# define COLOR_4G 0xC3
# define COLOR_4B 0x4E

# define COLOR_3 21
# define COLOR_3R 0x3B
# define COLOR_3G 0xA4
# define COLOR_3B 0x5A

# define COLOR_2 6
# define COLOR_2R 0xE0
# define COLOR_2G 0xCD
# define COLOR_2B 0xA9

# define COLOR_1 4
# define COLOR_1R 0x00
# define COLOR_1G 0xFF
# define COLOR_1B 0xFF

# define COLOR_0 2
# define COLOR_0R 0x00
# define COLOR_0G 0x00
# define COLOR_0B 0xFF

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_position
{
	size_t			x;
	size_t			y;
	int				height;
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
void			ft_color_0(t_mlx **mlx, t_position *pos1);
void			ft_color_1(t_mlx **mlx, t_position *pos1);
void			ft_color_2(t_mlx **mlx, t_position *pos1);
void			ft_color_3(t_mlx **mlx, t_position *pos1);
void			ft_color_4(t_mlx **mlx, t_position *pos1);
void			ft_color_5(t_mlx **mlx, t_position *pos1);
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
