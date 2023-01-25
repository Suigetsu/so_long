/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lower_upwall_imgs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:35:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	upper_wall_imgs(t_vars *var)
{
	var->img.upwall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_uwall, &var->img_x, &var->img_y);
	if (!var->img.upwall)
		free_pokemon(var);
	var->img.upl_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_ulwall, &var->img_x, &var->img_y);
	if (!var->img.upl_wall)
		free_pokemon(var);
	var->img.upr_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_urwall, &var->img_x, &var->img_y);
	if (!var->img.upr_wall)
		free_pokemon(var);
}

void	lower_wall_imgs(t_vars *var)
{
	var->img.lowall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lwall, &var->img_x, &var->img_y);
	if (!var->img.lowall)
		free_pokemon(var);
	var->img.lol_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_llwall, &var->img_x, &var->img_y);
	if (!var->img.lol_wall)
		free_pokemon(var);
	var->img.lor_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lrwall, &var->img_x, &var->img_y);
	if (!var->img.lor_wall)
		free_pokemon(var);
}
