/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mapread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:13:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/19 22:42:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_read(char *filename, t_vars *var)
{
	int				fd;
	char			*s;

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

void	map_copy(t_vars *var, t_additionals *mapcpy)
{
	int	i;

	i = 0;
	mapcpy->mapcopy = malloc(6 * sizeof(char *));
	while (var->w_h.game[i])
	{
		mapcpy->mapcopy[i] = ft_strdup(var->w_h.game[i]);
		i++;
	}
}
