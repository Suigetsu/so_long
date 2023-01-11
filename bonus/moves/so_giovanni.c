/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_giovanni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:33:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/11 21:37:36 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	giovanni_rmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'G' \
			&& var->w_h.game[var->i][var->j + 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'G';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e3.threeright, (var->j + 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	giovanni_lmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'G' \
			&& var->w_h.game[var->i][var->j - 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'G';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e3.threeleft, (var->j - 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	giovanni_upmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'G' \
			&& var->w_h.game[var->i - 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'G';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e3.threeup, var->j * 64, (var->i - 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	giovanni_downmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'G' \
			&& var->w_h.game[var->i + 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'G';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e3.threedown, var->j * 64, (var->i + 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

int	giovanni_moves(t_vars *var)
{
	static int	step;

	step++;
	srand(time(0));
	if (step == 5000)
	{
		if (rand() % 4 == 0)
			giovanni_rmoves(var);
		else if (rand() % 4 == 1)
			giovanni_upmoves(var);
		else if (rand() % 4 == 2)
			giovanni_lmoves(var);
		else
			giovanni_downmoves(var);
		step = 0;
	}
	return (0);
}