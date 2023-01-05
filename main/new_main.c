/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:55:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/04 16:18:34 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main()
{
	t_vars	var;
	int		c;
	
	var.mlx = mlx_init();
	map_read(&var);
	var.win = mlx_new_window(var.mlx, var.w_h.width * 64, var.w_h.height * 64, "poketest");
	upper_img(&var);
	upper_wall(&var);
    left_wall(&var);
    lower_wall(&var);
    right_wall(&var);
    obs(&var);
    coll(&var);
	playerone(&var);
	playertwo(&var);
	playerthree(&var);
    show_player(&var);
	// exit_game(&var);
	exit_xy(&var);
	mlx_hook(var.win, 2, 0, keys, &var);
	mlx_loop(var.mlx);
}