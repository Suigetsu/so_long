/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:57:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/12 16:44:50 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	window_destroyer(int key, t_vars *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(1);
	}
	return (0);
}

int	keys(int key, t_vars *var)
{
	int	i;
	
	i = 0;
	if (coll_scan(var) == 1)
	{
		
		if (key == 2)
			i = right_exit(key, var);
		else if (key == 13)
			i = up_exit(key, var);
		else if (key == 1)
			i = down_exit(key, var);
		else if (key == 0)
			i = left_exit(key, var);
		else if (key == 53)
			i = window_destroyer(key, var);
	}
	if (key == 2)
		i = right_move(key, var);
	else if (key == 13)
		i = up_move(key, var);
	else if (key == 1)
		i = down_move(key, var);
	else if (key == 0)
		i = left_move(key, var);
	else if (key == 53)
		i = window_destroyer(key, var);
	if (coll_scan(var) == 1)
		exit_game(var);
	return (i);
}

// int	exit_win(int key, t_vars *var)
// {
// 	int	i;

// 	if (coll_scan(var) == 1)
// 	{
// 		if (var->w_h.game[var->i][var->j + 1] == 'E' && key == 2)
// 		{
// 			i = right_move(key, var);
// 			exit(1);
// 		}
// 		else if (var->w_h.game[var->i - 1][var->j] == 'E' && key == 13)
// 		{
// 			i = up_move(key, var);
// 			exit(1);
// 		}
// 		else if (var->w_h.game[var->i + 1][var->j] == 'E' && key == 1)
// 		{
// 			i = down_move(key, var);
// 			exit(1);
// 		}
// 		else if (var->w_h.game[var->i][var->j - 1] == 'E' && key == 0)
// 		{
// 			i = left_move(key, var);
// 			exit(1);
// 		}
// 		else if (key == 53)
// 			i = window_destroyer(key, var);
// 	}
// 	return (0);
// }