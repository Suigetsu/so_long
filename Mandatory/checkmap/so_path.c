/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:48:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/19 17:19:28 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	pathfinding(int x, int y, t_additionals *mapcpy)
{
	if (mapcpy->mapcopy[x][y + 1] != '1' && mapcpy->mapcopy[x][y + 1])
	{
		mapcpy->mapcopy[x][y + 1] = '1';
		pathfinding(x, y + 1, mapcpy);
	}
	else if (mapcpy->mapcopy[x][y - 1] != '1' && mapcpy->mapcopy[x][y - 1])
	{
		mapcpy->mapcopy[x][y - 1] = '1';
		pathfinding(x, y - 1, mapcpy);
	}
	else if (mapcpy->mapcopy[x - 1][y] != '1' && mapcpy->mapcopy[x - 1][y])
	{
		mapcpy->mapcopy[x - 1][y] = '1';
		pathfinding(x - 1, y, mapcpy);
	}
	else if (mapcpy->mapcopy[x + 1][y] != '1' && mapcpy->mapcopy[x + 1][y])
	{
		mapcpy->mapcopy[x + 1][y] = '1';
		pathfinding(x + 1, y, mapcpy);
	}
	else
		return (1);
	return (0);
}

void	player_finder(t_vars *var, t_additionals *mapcpy)
{
	int	i;
	int j;

	i = 0;
	while (i < var->w_h.height)
	{
		j = 0;
		while (j < var->w_h.width)
		{
			if (mapcpy->mapcopy[i][j] == 'P')
			{
				if (pathfinding(i, j, mapcpy) == 1)
					return ;
			}
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
			if (mapcpy->mapcopy[i][j] == 'E'|| mapcpy->mapcopy[i][j] == 'C' \
				|| mapcpy->mapcopy[i][j] == 'P')
				{
					ft_printf("Erorr: valid path doesn't exist.\n");
					i = 0;
					while (mapcpy->mapcopy[i])
						free (mapcpy->mapcopy[i++]);
					exit(1);
				}
			j++;
		}
		i++;
	}
	// free (map->mapcopy);
}