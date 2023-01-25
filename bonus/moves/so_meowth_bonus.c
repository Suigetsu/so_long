/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_meowth_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:41:10 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	meowth_rmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'M' \
			&& var->w_h.game[var->i][var->j + 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'M';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->meowth.right, (var->j + 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	meowth_lmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'M' \
			&& var->w_h.game[var->i][var->j - 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'M';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->meowth.left, (var->j - 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	meowth_upmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'M' \
			&& var->w_h.game[var->i - 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'M';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->meowth.up, var->j * 64, (var->i - 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	meowth_downmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'M' \
			&& var->w_h.game[var->i + 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'M';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->meowth.down, var->j * 64, (var->i + 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

int	meowth_moves(t_vars *var)
{
	static int	step;

	step++;
	srand(time(0));
	if (step == 5000)
	{
		if (rand() % 4 == 0)
			meowth_rmoves(var);
		else if (rand() % 4 == 1)
			meowth_upmoves(var);
		else if (rand() % 4 == 2)
			meowth_lmoves(var);
		else
			meowth_downmoves(var);
		step = 0;
	}
	return (0);
}
