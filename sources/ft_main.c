/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:21 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/23 14:22:31 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_open(av[1]) == -1)
		{
			write(2, "Error.\n", 7);
			return (1);
		}
	}
	else
	{
		write(2, "Usage: ./fdf [file]\n", 20);
	}
	return (0);
}
