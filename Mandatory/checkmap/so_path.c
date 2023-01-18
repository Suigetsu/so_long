/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:48:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/18 17:32:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	player_coord(t_vars *var)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < var->w_h.height)
	{
		j = 0;
		while (j < var->w_h.width)
		{
			if (var->w_h.game[i][j] == 'P')
			{
				pathfinding(i, j, var);
			}
			j++;
		}
		i++;
	}
}

void	pathfinding(int x, int y, t_vars *var)
{
	var->i = 1;
	var->j = 1;
	
	if (var->mapcopy[x][y + 1] != '1')
	{
		var->mapcopy[x][y + 1] = '1';
		pathfinding(x, y + 1, var);
	}
	else if (var->mapcopy[x + 1][y] != '1')
	{
		var->mapcopy[x + 1][y] = '1';
		pathfinding(x + 1, y, var);
	}
	else if (var->mapcopy[x][y - 1] != '1')
	{
		var->mapcopy[x][y - 1] = '1';
		pathfinding(x, y - 1, var);
	}
	else if (var->mapcopy[x - 1][y] != '1')
	{
		var->mapcopy[x - 1][y] = '1';
		pathfinding(x - 1, y, var);
	}
}

static void	char_counter(t_vars *var)