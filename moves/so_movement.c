/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:04:08 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/06 12:09:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	g_count;
static int	g_c;
static int	g_exit_x;
static int	g_exit_y;
static int	g_movecount;

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
				var->w_h.game[g_exit_x][g_exit_y] = 'E';
				if (var->w_h.game[var->i][var->j + 1] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j + 1] = 'P';
				right_evolution(g_count, var);
				g_movecount += 1;
				ft_printf("movement count: %d\n", g_movecount);
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
				var->w_h.game[g_exit_x][g_exit_y] = 'E';
				if (var->w_h.game[var->i][var->j - 1] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i][var->j - 1] = 'P';
				left_evolution(g_count, var);
				g_movecount += 1;
				ft_printf("movement count: %d\n", g_movecount);
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
				var->w_h.game[g_exit_x][g_exit_y] = 'E';
				if (var->w_h.game[var->i - 1][var->j] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i - 1][var->j] = 'P';
				up_evolution(g_count, var);
				g_movecount += 1;
				ft_printf("movement count: %d\n", g_movecount);
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
				var->w_h.game[g_exit_x][g_exit_y] = 'E';
				if (var->w_h.game[var->i + 1][var->j] == 'C')
					g_count += 1;
				var->w_h.game[var->i][var->j] = '0';
				var->w_h.game[var->i + 1][var->j] = 'P';
				down_evolution(g_count, var);
				g_movecount += 1;
				ft_printf("movement count: %d\n", g_movecount);
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
				g_exit_x = var->i;
				g_exit_y = var->j;
			}
			var->j++;
		}
		var->i++;
	}
}
