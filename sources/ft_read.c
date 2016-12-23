/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:39:35 by jcarra            #+#    #+#             */
/*   Updated: 2016/12/23 11:39:37 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_read(char *name, int size)
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

int	ft_open(char *name)
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
	if (ft_parsing(str) == -1)
		return (-1);
	return (0);
}
