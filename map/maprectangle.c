/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maprectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:02:18 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/23 19:32:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
