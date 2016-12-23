/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:35 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/23 15:04:06 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t		ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n])
		n = n + 1;
	return (n);
}

static char	*ft_read(char *name, int size)
{
	char	*str;
	int		fd;
	int		ret;

	if ((str = malloc(size + 1)) == NULL)
		return (NULL);
	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	ret = read(fd, str, size);
	str[ret] = '\0';
	close(fd);
	return (str);
}

static int	ft_error(char *str)
{
	size_t	n;

	n = 0;
	while (str[n] && str[n] != '\n')
	{
		if (str[n] != '0' && str[n] != ' ')
			return (-1);
		n = n + 1;
	}
	if (ft_strlen(str) < 7)
		return (-1);
	n = (str[ft_strlen(str) - 1] == '\n') ?
		ft_strlen(str) - 2 : ft_strlen(str) - 1;
	while (n > 0 && str[n] != '\n')
	{
		if (str[n] != '0' && str[n] != ' ')
			return (-1);
		n = n - 1;
	}
	return (0);
}

int			ft_open(char *name)
{
	char	*str;
	char	c;
	int		fd;
	int		size	= 0;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		size = size + 1;
	close(fd);
	if ((str = ft_read(name, size)) == NULL)
		return (-1);
//	if (ft_error(str) == -1)
//		return (-1);
	if (ft_parsing(str) == -1)
		return (-1);
	return (0);
}
