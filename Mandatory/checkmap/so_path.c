/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:48:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 12:40:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
	int	i;
	int	j;

	i = 1;
	while (i < var->w_h.height)
	{
		j = 1;
		while (j < var->w_h.width)
		{
			if (mapcpy->mapcopy[i][j] == 'E' || mapcpy->mapcopy[i][j] == 'C' \
				|| mapcpy->mapcopy[i][j] == 'P')
			{
				ft_printf("Erorr: valid path doesn't exist.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
