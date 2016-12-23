/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:07 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/23 14:11:55 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_abs(int n)
{
  if (n >= 0)
    return (n);
  else
    return (-n);
}

int	ft_around(unsigned int a, unsigned int b)
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

int	ft_atoi_spe(char *str, int pos)
{
  int	res = 0;
  int	neg = 1;
  int	n = pos;

  while (str[n] == ' ' || str[n] == '\t')
    n = n + 1;
  if (str[n] == '-')
	  return (-1);
  while (str[n] >= '0' && str[n] <= '9')
    res = (res * 10) + (str[n++] - '0');
  return (res * neg);
}

int	ft_max(t_map *map)
{
  int	nbr;
  int	x;
  int	y;

  y = 0;
  nbr = 1;
  while (y < map->line)
    {
      x = -1;
      while (++x < map->column)
	if (nbr < map->tab[y][x])
	  nbr = map->tab[y][x];
      y = y + 1;
    }
  return (nbr);
}
