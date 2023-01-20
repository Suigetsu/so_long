/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:57:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 22:44:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	window_destroyer(int key, t_vars *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(1);
	}
	return (0);
}

int	destroy_with_mouse(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(1);
	return (0);
}

static int	enemy_exit(t_vars *var)
{
	james_exit(var);
	jessie_exit(var);
	giovanni_exit(var);
	meowth_exit(var);
}

int	keys(int key, t_vars *var)
{
	if (coll_scan(var) == 1)
		exit_win(key, var);
	if (key == 2)
	{
		enemy_exit(var);
		right_move(key, var);
	}
	else if (key == 13)
	{
		enemy_exit(var);
		up_move(key, var);
	}
	else if (key == 1)
	{
		enemy_exit(var);
		down_move(key, var);
	}
	else if (key == 0)
	{
		enemy_exit(var);
		left_move(key, var);
	}
	else if (key == 53)
		window_destroyer(key, var);
	return (0);
}

void	exit_win(int key, t_vars *var)
{
	exit_game(var);
	if (key == 2)
		right_exit(key, var);
	else if (key == 13)
		up_exit(key, var);
	else if (key == 1)
		down_exit(key, var);
	else if (key == 0)
		left_exit(key, var);
	else if (key == 53)
		window_destroyer(key, var);
}
