/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:48:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	pathfinding(int x, int y, t_additionals *mapcpy)
{
	if (mapcpy->mapcopy[x][y + 1] != '1' && mapcpy->mapcopy[x][y + 1])
	{
		mapcpy->mapcopy[x][y + 1] = '1';
		pathfinding(x, y + 1, mapcpy);
	}
	if (mapcpy->mapcopy[x][y - 1] != '1' && mapcpy->mapcopy[x][y - 1])
	{
		mapcpy->mapcopy[x][y - 1] = '1';
		pathfinding(x, y - 1, mapcpy);
	}
	if (mapcpy->mapcopy[x - 1][y] != '1' && mapcpy->mapcopy[x - 1][y])
	{
		mapcpy->mapcopy[x - 1][y] = '1';
		pathfinding(x - 1, y, mapcpy);
	}
	if (mapcpy->mapcopy[x + 1][y] != '1' && mapcpy->mapcopy[x + 1][y])
	{
		mapcpy->mapcopy[x + 1][y] = '1';
		pathfinding(x + 1, y, mapcpy);
	}
	else
		return ;
}

void	player_finder(t_vars *var, t_additionals *mapcpy)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->w_h.height)
	{
		j = 0;
		while (j < var->w_h.width)
		{
			if (mapcpy->mapcopy[i][j] == 'P')
				pathfinding(i, j, mapcpy);
			j++;
		}
		i++;
	}
}

void	valid_path(t_vars *var, t_additionals *mapcpy)
{
	var->i = 0;
	while (var->i < var->w_h.height)
	{
		var->j = 0;
		while (var->j < var->w_h.width)
		{
			if (mapcpy->mapcopy[var->i][var->j] == 'E' || \
				mapcpy->mapcopy[var->i][var->j] == 'C' || \
				mapcpy->mapcopy[var->i][var->j] == 'P')
			{
				ft_printf("Erorr: valid path doesn't exist.\n");
				var->i = 0;
				while (mapcpy->mapcopy[var->i])
					free(mapcpy->mapcopy[var->i++]);
				free(mapcpy->mapcopy);
				free_pokemon(var);
			}
			var->j++;
		}
		var->i++;
	}
	var->i = 0;
	while (mapcpy->mapcopy[var->i])
		free(mapcpy->mapcopy[var->i++]);
	free(mapcpy->mapcopy);
}
