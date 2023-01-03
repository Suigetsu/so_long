/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:04:08 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/03 05:42:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	g_count;
static int	g_c;

int	right_move(int key, t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i][var->j + 1] != '1')
			{
				if (var->w_h.game[var->i][var->j + 1] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'P';
				right_evolution(g_count, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	left_move(int key, t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i][var->j - 1] != '1')
			{
				if (var->w_h.game[var->i][var->j - 1] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'P';
				left_evolution(g_count, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	up_move(int key, t_vars *var)
{
	var->i = 0;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i - 1][var->j] != '1')
			{
				if (var->w_h.game[var->i - 1][var->j] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'P';
				up_evolution(g_count, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	down_move(int key, t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i + 1][var->j] != '1')
			{
				if (var->w_h.game[var->i + 1][var->j] == 'C')
					g_count += 1;
				if (var->w_h.game[var->i + 1][var->j] == 'E')
					{
						var->w_h.game[var->i][var->j] = '0';
						var->w_h.game[var->i + 2][var->j] = 'P';
						down_evolution(g_count, var);
					}
				else
				{
					var->w_h.game[var->i][var->j] = '0';
					var->w_h.game[var->i + 1][var->j] = 'P';
					down_evolution(g_count, var);
				}
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

void	exit_game(t_vars *var)
{
	var->i = 1;
	var->path.path_exit = "sprites/xpm/world/center1671710820.xpm";
	var->img.exit = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_exit, &var->img_x, &var->img_y);
	// g_c = collectibles("main/map.ber");
	// ft_printf("count: %d | collected: %d\n", g_c, g_count);
	// if (g_c == g_count)
	// {
		ft_printf("count: %d | collected: %d\n", g_c, g_count);
		while (var->i < var->w_h.height - 1)
		{
			var->j = 1;
			while (var->j < var->w_h.width - 1)
			{
				if (var->w_h.game[var->i][var->j] == 'E')
					mlx_put_image_to_window(var->mlx, \
					var->win, var->img.exit, var->j * 64, var->i * 64);
				var->j++;
			}
			var->i++;
		}

}