/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:07 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:51:00 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int			ft_around(unsigned int a, unsigned int b)
{
	if (b % 2 == 0)
	{
		if (a % b >= b / 2)
			return (a / b + 1);
		else
			return (a / b);
	}
	else
	{
		if (a % b > b / 2)
			return (a / b + 1);
		else
			return (a / b);
	}
}

int			ft_atoi_spe(char *str, int n)
{
	int		res;
	int		neg;

	res = 0;
	neg = 1;
	while (str[n] == ' ' || str[n] == '\t')
		n = n + 1;
	if (str[n] == '-')
	{
		neg = -1;
		n = n + 1;
	}
	while (str[n] >= '0' && str[n] <= '9')
		res = (res * 10) + (str[n++] - '0');
	return (res * neg);
}

int			ft_max(t_map *map)
{
	size_t	x;
	size_t	y;
	int		nbr;

	y = 0;
	nbr = map->tab[0][0];
	while (y < map->line)
	{
		x = 0;
		while (x < map->column)
			if (nbr < map->tab[y][x++])
				nbr = map->tab[y][x - 1];
		y = y + 1;
	}
	return (nbr);
}

int			ft_min(t_map *map)
{
	size_t	x;
	size_t	y;
	int		nbr;

	y = 0;
	nbr = map->tab[0][0];
	while (y < map->line)
	{
		x = 0;
		while (x < map->column)
			if (map->tab[y][x++] < nbr)
				nbr = map->tab[y][x - 1];
		y = y + 1;
	}
	return (nbr);
}
