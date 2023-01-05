/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:40:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/02 19:49:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(void)
{
	t_vars	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 64, 64, "pokegame");
	//map_read(&var);
	mlx_loop(var.mlx);
}
