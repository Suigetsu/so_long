/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:57:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/03 02:51:36 by mlagrini         ###   ########.fr       */
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
	return (0);
}
