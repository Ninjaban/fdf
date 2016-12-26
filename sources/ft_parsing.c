/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:29 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:51:11 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static size_t	ft_get_value(char *str, int column)
{
	size_t	n;
	size_t	line;
	size_t	value;

	n = 0;
	line = 0;
	value = 0;
	while (str[n] != '\0')
		if (str[n] >= '0' && str[n] <= '9')
		{
			value = value + 1;
			while (str[n] >= '0' && str[n] <= '9')
				n = n + 1;
		}
		else if (str[n++] == '\n')
		{
			if (column == FALSE)
				line = line + 1;
			else
				return (value);
		}
	line = (!str[n] && str[n - 1] == '\n') ? line : line + 1;
	return (line);
}

static void		ft_init_tab(t_map **map, char *str)
{
	size_t	n;
	size_t	x;
	size_t	y;

	n = 0;
	y = 0;
	x = 0;
	while (str[n] != '\0')
	{
		if (str[n] == '\n')
		{
			y = y + 1;
			x = 0;
			n = n + 1;
		}
		while (str[n] == ' ')
			n = n + 1;
		if (str[n] && str[n] != '\n')
			(*map)->tab[y][x++] = ft_atoi_spe(str, n);
		while (str[n] && str[n] != ' ' && str[n] != '\n')
			n = n + 1;
	}
}

static void		ft_tab_min(t_map **map)
{
	size_t	x;
	size_t	y;
	int		min;

	y = 0;
	min = ft_min((*map));
	if (min < 0)
	{
		while (y < (*map)->line)
		{
			x = 0;
			while (x < (*map)->column)
				(*map)->tab[y][x++] += ft_abs(min);
			y = y + 1;
		}
	}
}

int				ft_parsing(char *str)
{
	t_map	*map;
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	if ((map = malloc(sizeof(t_map))) == NULL)
		return (-1);
	map->line = ft_get_value(str, FALSE);
	map->column = ft_get_value(str, TRUE);
	if ((map->tab = malloc(sizeof(int *) * map->line)) == NULL)
		return (-1);
	while (i < map->line)
		if ((map->tab[i++] = malloc(sizeof(int) * map->column)) == NULL)
			return (-1);
	ft_init_tab(&map, str);
	ft_tab_min(&map);
	if (ft_fdf(map) == -1)
		return (-1);
	return (0);
}
