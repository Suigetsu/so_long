/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:55:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/02 23:39:08 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main()
{
	t_vars	var;
	
	var.mlx = mlx_init();
	map_read(&var);
	ft_printf("%d, %d\n", var.w_h.width, var.w_h.height);
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
	exit_game(&var);
	mlx_hook(var.win, 2, 0, keys, &var);
	mlx_loop(var.mlx);
}