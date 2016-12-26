/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:35 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/26 09:48:13 by jcarra           ###   ########.fr       */
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

static int	ft_get_value(char *str, int column)
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

static int	ft_error(char *str)
{
	size_t	n;

	if (ft_get_value(str, FALSE) < 2)
		return (-1);
	if (ft_get_value(str, TRUE) < 2)
		return (-1);
	n = 0;
	while (str[n])
	{
		if ((str[n] < '0' || str[n] > '9') && str[n] != ' ' &&
			str[n] != '\n' && str[n] != '-')
			return (-1);
		n = n + 1;
	}
	return (0);
}

int			ft_open(char *name)
{
	char	*str;
	char	c;
	int		fd;
	int		size;

	size = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		size = size + 1;
	close(fd);
	if ((str = ft_read(name, size)) == NULL)
		return (-1);
	if (ft_error(str) == -1)
		return (-1);
	if (ft_parsing(str) == -1)
		return (-1);
	return (0);
}
