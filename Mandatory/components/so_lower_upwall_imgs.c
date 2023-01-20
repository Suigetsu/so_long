/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lower_upwall_imgs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:35:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 15:37:56 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	upper_wall_imgs(t_vars *var)
{
	var->img.upwall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_uwall, &var->img_x, &var->img_y);
	if (!var->img.upwall)
		exit (1);
	var->img.upl_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_ulwall, &var->img_x, &var->img_y);
	if (!var->img.upl_wall)
		exit (1);
	var->img.upr_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_urwall, &var->img_x, &var->img_y);
	if (!var->img.upr_wall)
		exit (1);
}

void	lower_wall_imgs(t_vars *var)
{
	var->img.lowall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lwall, &var->img_x, &var->img_y);
	if (!var->img.lowall)
		exit (1);
	var->img.lol_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_llwall, &var->img_x, &var->img_y);
	if (!var->img.lol_wall)
		exit (1);
	var->img.lor_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lrwall, &var->img_x, &var->img_y);
	if (!var->img.lor_wall)
		exit (1);
}
