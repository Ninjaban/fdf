#ifndef TOOLS_H
# define TOOLS_H

# define	FALSE 0
# define	TRUE 1
# define	WIDTH 1920
# define	HEIGHT 1080

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct	s_position
{
	unsigned int	x;
	unsigned int	y;
}				t_position;

typedef struct	s_map
{
  int				**tab;
  int				line;
  int				column;
}				t_map;

typedef struct	s_draw
{
  t_position	**tab;
  unsigned int	size;
  unsigned int	incup;
}		t_draw;

typedef struct	s_mlx
{
	void			*mlx;
	void		*win;
  void *img;
}				t_mlx;

void	ft_draw_image(t_mlx *mlx);
int	ft_open(char *name);
int	ft_parsing(char *str);
int	ft_fdf(t_map *map);
int	ft_abs(int n);
int	ft_max(t_map *map);
int	ft_atoi_spe(char *str, int pos);
int	ft_around(unsigned int a, unsigned int b);
int	aff_line(t_mlx *mlx, t_position pos1, t_position pos2);
t_mlx	*ft_init_mlx(void);
t_draw	*ft_init_draw(t_map *map);
t_draw	*ft_init_draw_function(t_draw *draw, t_map *map,
			       unsigned int incx, unsigned int incy);

#endif
