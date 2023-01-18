/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_wallcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:30:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/16 13:09:47 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	upperwall(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	lowerwall(char	*filename)
{
	int		fd;
	int		c;
	int		len;
	char	*s;

	c = 0;
	len = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		free (s);
		s = get_next_line(fd);
		c += 1;
	}
	free (s);
	close (fd);
	fd = open(filename, O_RDONLY);
	while (len < c)
	{
		s = get_next_line(fd);
		len++;
		free (s);
	}
	c = upperwall(s);
	if (c <= 0)
		return (0);
	return (1);
}

int	wall_of_maria(char *filename)
{
	int		fd;
	int		c;
	int		len;
	char	*s;

	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	len = ft_strlen(s);
	c = upperwall(s);
	if (c <= 0)
		return (0);
	c = 0;
	while (s)
	{
		if (s[0] != '1' || s[len - 2] != '1')
		{
			free (s);
			return (0);
		}
		free (s);
		s = get_next_line(fd);
		c += 1;
	}
	free (s);
	close (fd);
	c = lowerwall(filename);
	if (c <= 0)
		return (0);
	return (1);
}
