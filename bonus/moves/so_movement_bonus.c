/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:04:08 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 14:58:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	right_move(t_vars *var)
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
				var->w_h.game[var->exit_x][var->exit_y] = 'E';
				if (var->w_h.game[var->i][var->j + 1] == 'C')
					var->e_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'P';
				right_evolution(var->e_count, var);
				var->movecount += 1;
				move_counter(var->movecount, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	left_move(t_vars *var)
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
				var->w_h.game[var->exit_x][var->exit_y] = 'E';
				if (var->w_h.game[var->i][var->j - 1] == 'C')
					var->e_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'P';
				left_evolution(var->e_count, var);
				var->movecount += 1;
				move_counter(var->movecount, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	up_move(t_vars *var)
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
				var->w_h.game[var->exit_x][var->exit_y] = 'E';
				if (var->w_h.game[var->i - 1][var->j] == 'C')
					var->e_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'P';
				up_evolution(var->e_count, var);
				var->movecount += 1;
				move_counter(var->movecount, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	down_move(t_vars *var)
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
				var->w_h.game[var->exit_x][var->exit_y] = 'E';
				if (var->w_h.game[var->i + 1][var->j] == 'C')
					var->e_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'P';
				down_evolution(var->e_count, var);
				var->movecount += 1;
				move_counter(var->movecount, var);
				return (0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

void	exit_xy(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'E')
			{
				var->exit_x = var->i;
				var->exit_y = var->j;
			}
			var->j++;
		}
		var->i++;
	}
}
