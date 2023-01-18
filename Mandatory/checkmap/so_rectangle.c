/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:29:26 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/16 13:09:25 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	calculatrice(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	maprectangle(char *filename)
{
	int		fd;
	char	*line;
	int		linesize;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	linesize = calculatrice(line);
	while (line)
	{
		if (calculatrice(line) != linesize)
		{
			free (line);
			return (0);
		}
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (1);
}
