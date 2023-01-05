/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:15:45 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/28 00:25:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    player(t_vars *var)
{
    var->i = 1;
    var->p_one.p_one_path1 = "../sprites/xpm/01/01_right011671529027.xpm";
    var->p_one.p_one_path2 = "../sprites/xpm/01/01_right031671529028.xpm";
    var->p->p1 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path1, &var->img_x, &var->img_y);
    var->p->p2 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path2, &var->img_x, &var->img_y);
    while (var->i < var->w_h.height - 1)
    {
        var->j = 1;
        while (var->j < var->w_h.width - 1)
        {
            if (var->w_h.game[var->i][var->j] == 'P')
                mlx_put_image_to_window(var->mlx, var->win, var->p->p1, var->j * 64, var->i * 64);
            var->j++;
        }
        var->i++;
    }
}

int right_move(int key, t_vars *var)
{
    var->i = 1;
    var->count = 0;
    while (var->i < var->w_h.height - 1)
    {
        var->j = 1;
        while (var->j < var->w_h.width - 2)
		{
			if (key == 2)
			{
				if (var->w_h.game[var->i][var->j] == 'P' && (var->w_h.game[var->i][var->j + 1] == '0' || var->w_h.game[var->i][var->j + 1] == 'P'))
				{
					var->w_h.game[var->i][var->j] = '0';
					var->w_h.game[var->i][var->j + 1] = 'P';
					mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
                    mlx_put_image_to_window(var->mlx, var->win, var->p->p1, (var->j + 1) * 64, var->i * 64);
					break;
				}
			}
		}
	}
}