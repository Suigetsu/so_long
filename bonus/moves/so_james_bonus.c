/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_james_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	james_rmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'A' \
			&& var->w_h.game[var->i][var->j + 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'A';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e1.oneright, (var->j + 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	james_lmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'A' \
			&& var->w_h.game[var->i][var->j - 1] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'A';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e1.oneleft, (var->j - 1) * 64, var->i * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	james_upmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'A' \
			&& var->w_h.game[var->i - 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'A';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e1.oneup, var->j * 64, (var->i - 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

static void	james_downmoves(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'A' \
			&& var->w_h.game[var->i + 1][var->j] == '0')
			{
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'A';
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e1.onedown, var->j * 64, (var->i + 1) * 64);
				return ;
			}
			var->j++;
		}
		var->i++;
	}
	return ;
}

int	james_moves(t_vars *var)
{
	static int	step;

	step++;
	srand(time(0));
	if (step == 5000)
	{
		if (rand() % 4 == 0)
			james_rmoves(var);
		else if (rand() % 4 == 1)
			james_upmoves(var);
		else if (rand() % 4 == 2)
			james_lmoves(var);
		else
			james_downmoves(var);
		step = 0;
	}
	return (0);
}
