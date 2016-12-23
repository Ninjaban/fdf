/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:29 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/23 14:49:51 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			ft_get_value(char *str, int column)
{
	int	line	= 0;
	int	value	= 0;
	int	n		= 0;

	while (str[n] != '\0')
    {
		if (str[n] >= '0' && str[n] <= '9')
		{
			value = value + 1;
			while (str[n] >= '0' && str[n] <= '9')
				n = n + 1;
		}
		if (str[n] == '\n')
		{
			if (column == FALSE)
				line = line + 1;
			else
				return (value);
		}
		n = n + 1;
    }
	line = (!str[n] && str[n - 1] == '\n') ? line : line + 1;
	return (line);
}

int			ft_parsing(char *str)
{
	t_map	*map;
	int	n	= 0;
	int	x	= 0;
	int	y	= -1;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (-1);
	map->line = ft_get_value(str, FALSE);
	map->column = ft_get_value(str, TRUE);
	if ((map->tab = malloc(sizeof(int *) * map->line)) == NULL)
		return (-1);
	while (str[n] != '\0')
    {
		if ((str[n] == '\n' || n == 0) && str[n + 1] != '\0')
		{
			if ((map->tab[++y] = malloc(sizeof(int) * map->column)) == NULL)
				return (-1);
			x = 0;
		}
		if (str[n] >= '0' && str[n] <= '9')
		{
		    if ((map->tab[y][x++] = ft_atoi_spe(str, n)) == -1)
				return (-1);
		    while (str[n] >= '0' && str[n] <= '9')
				n = n + 1;
		}
		else
			n = n + 1;
    }
	if (ft_fdf(map) == -1)
		return (-1);
	return (0);
}
