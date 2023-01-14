/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mapread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:13:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:21 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_read(char *filename, t_vars *var)
{
	int		fd;
	char	*s;

	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	var->w_h.width = ft_strlen(s) - 1;
	var->w_h.height = 1;
	var->w_h.map = ft_strdup(s);
	free (s);
	while (s)
	{
		s = get_next_line(fd);
		if (!s)
		{
			close (fd);
			free (s);
			break ;
		}
		var->w_h.map = ft_strjoin(var->w_h.map, s);
		free (s);
		var->w_h.height += 1;
	}
	var->w_h.game = ft_split(var->w_h.map, '\n');
	free (var->w_h.map);
}