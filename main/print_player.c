/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:05:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/01 19:10:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    player(t_vars *var)
{
    var->i = 1;
    var->p_one.p_one_path1 = "../sprites/xpm/03/03_right011671529272.xpm";
    var->p_one.p_one_path2 = "../sprites/xpm/03/03_right031671529272.xpm";
    var->p_one.p_one_img1 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path1, &var->img_x, &var->img_y);
    var->p_one.p_one_img2 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path2, &var->img_x, &var->img_y);
    while (var->i < var->w_h.height - 1)
    {
        var->j = 1;
        while (var->j < var->w_h.width - 1)
        {
            if (var->w_h.game[var->i][var->j] == 'P')
                mlx_put_image_to_window(var->mlx, var->win, var->p_one.p_one_img1, var->j * 64, var->i * 64);
            var->j++;
        }
        var->i++;
    }
}

void    player_up(t_vars *var)
{
    var->p_one.p_one_path3 = "../sprites/xpm/03/03_up011671529272.xpm";
    var->p_one.p_one_path4 = "../sprites/xpm/03/03_up031671529273.xpm";
    var->p_one.p_one_img3 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path3, &var->img_x, &var->img_y);
    var->p_one.p_one_img4 = mlx_xpm_file_to_image(var->mlx, var->p_one.p_one_path4, &var->img_x, &var->img_y);
}

void    player_down(t_vars *var)
{
    var->p_two.p_two_path1 = "../sprites/xpm/03/03_down011671529271.xpm";
    var->p_two.p_two_path2 = "../sprites/xpm/03/03_down031671529271.xpm";
    var->p_two.p_two_img1 = mlx_xpm_file_to_image(var->mlx, var->p_two.p_two_path1, &var->img_x, &var->img_y);
    var->p_two.p_two_img2 = mlx_xpm_file_to_image(var->mlx, var->p_two.p_two_path2, &var->img_x, &var->img_y);
}

void    player_left(t_vars *var)
{
    var->p_two.p_two_path3 = "../sprites/xpm/03/03_left011671529271.xpm";
    var->p_two.p_two_path4 = "../sprites/xpm/03/03_left031671529272.xpm";
    var->p_two.p_two_img3 = mlx_xpm_file_to_image(var->mlx, var->p_two.p_two_path3, &var->img_x, &var->img_y);
    var->p_two.p_two_img4 = mlx_xpm_file_to_image(var->mlx, var->p_two.p_two_path4, &var->img_x, &var->img_y);
}