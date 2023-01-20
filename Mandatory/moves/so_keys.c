/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:57:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 13:07:03 by mlagrini         ###   ########.fr       */
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

static int	exit_keys(int key, t_vars *var)
{
	if (key == 2)
		right_exit(var);
	else if (key == 13)
		up_exit(var);
	else if (key == 1)
		down_exit(var);
	else if (key == 0)
		left_exit(var);
	else if (key == 53)
		window_destroyer(key, var);
	return (0);
}

int	keys(int key, t_vars *var)
{
	if (coll_scan(var) == 1)
		exit_keys(key, var);
	if (key == 2)
		right_move(var);
	else if (key == 13)
		up_move(var);
	else if (key == 1)
		down_move(var);
	else if (key == 0)
		left_move(var);
	else if (key == 53)
		window_destroyer(key, var);
	if (coll_scan(var) == 1)
		exit_game(var);
	return (0);
}
