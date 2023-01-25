/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_jessie_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:19:02 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	jessie_rmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'B' \
			&& var->w_h.game[var->i][var->j + 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'B';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e2.tworight, (var->j + 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	jessie_lmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'B' \
			&& var->w_h.game[var->i][var->j - 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'B';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e2.twoleft, (var->j - 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	jessie_upmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'B' \
			&& var->w_h.game[var->i - 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'B';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e2.twoup, var->j * 64, (var->i - 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	jessie_downmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'B' \
			&& var->w_h.game[var->i + 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'B';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e2.twodown, var->j * 64, (var->i + 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

int	jessie_moves(t_vars *var)
{
	static int	step;

	step++;
	srand(time(0));
	if (step == 5000)
	{
		if (rand() % 4 == 0)
			jessie_rmoves(var);
		else if (rand() % 4 == 1)
			jessie_upmoves(var);
		else if (rand() % 4 == 2)
			jessie_lmoves(var);
		else
			jessie_downmoves(var);
		step = 0;
	}
	return (0);
}
