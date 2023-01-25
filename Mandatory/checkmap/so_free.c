/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:59:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	destroy_walls(t_vars *var)
{
	if (var->img.upwall)
		mlx_destroy_image(var->mlx, var->img.upwall);
	if (var->img.upl_wall)
		mlx_destroy_image(var->mlx, var->img.upl_wall);
	if (var->img.upr_wall)
		mlx_destroy_image(var->mlx, var->img.upr_wall);
	if (var->img.lowall)
		mlx_destroy_image(var->mlx, var->img.lowall);
	if (var->img.lol_wall)
		mlx_destroy_image(var->mlx, var->img.lol_wall);
	if (var->img.lor_wall)
		mlx_destroy_image(var->mlx, var->img.lor_wall);
	if (var->img.left_wall)
		mlx_destroy_image(var->mlx, var->img.left_wall);
	if (var->img.bg)
		mlx_destroy_image(var->mlx, var->img.bg);
	if (var->img.right_wall)
		mlx_destroy_image(var->mlx, var->img.right_wall);
}

static void	destroy_other_component(t_vars *var)
{
	if (var->img.coll)
		mlx_destroy_image(var->mlx, var->img.coll);
	if (var->img.obs)
		mlx_destroy_image(var->mlx, var->img.obs);
	if (var->img.exit)
		mlx_destroy_image(var->mlx, var->img.exit);
	if (var->anim.frame1)
		mlx_destroy_image(var->mlx, var->anim.frame1);
	if (var->anim.frame2)
		mlx_destroy_image(var->mlx, var->anim.frame2);
	if (var->anim.frame3)
		mlx_destroy_image(var->mlx, var->anim.frame3);
	if (var->meowth.up)
		mlx_destroy_image(var->mlx, var->meowth.up);
	if (var->meowth.down)
		mlx_destroy_image(var->mlx, var->meowth.down);
	if (var->meowth.right)
		mlx_destroy_image(var->mlx, var->meowth.right);
	if (var->meowth.left)
		mlx_destroy_image(var->mlx, var->meowth.left);
}

static void	destroy_player(t_vars *var)
{
	if (var->p1.oneright1)
		mlx_destroy_image(var->mlx, var->p1.oneright1);
	if (var->p1.oneup1)
		mlx_destroy_image(var->mlx, var->p1.oneup1);
	if (var->p1.oneleft1)
		mlx_destroy_image(var->mlx, var->p1.oneleft1);
	if (var->p1.onedown1)
		mlx_destroy_image(var->mlx, var->p1.onedown1);
	if (var->p2.tworight1)
		mlx_destroy_image(var->mlx, var->p2.tworight1);
	if (var->p2.twoup1)
		mlx_destroy_image(var->mlx, var->p2.twoup1);
	if (var->p2.twoleft1)
		mlx_destroy_image(var->mlx, var->p2.twoleft1);
	if (var->p2.twodown1)
		mlx_destroy_image(var->mlx, var->p2.twodown1);
	if (var->p3.threeright1)
		mlx_destroy_image(var->mlx, var->p3.threeright1);
	if (var->p3.threeup1)
		mlx_destroy_image(var->mlx, var->p3.threeup1);
	if (var->p3.threeleft1)
		mlx_destroy_image(var->mlx, var->p3.threeleft1);
	if (var->p3.threedown1)
		mlx_destroy_image(var->mlx, var->p3.threedown1);
}

static void	destroy_enemies(t_vars *var)
{
	if (var->e1.oneup)
		mlx_destroy_image(var->mlx, var->e1.oneup);
	if (var->e1.onedown)
		mlx_destroy_image(var->mlx, var->e1.onedown);
	if (var->e1.oneright)
		mlx_destroy_image(var->mlx, var->e1.oneright);
	if (var->e1.oneleft)
		mlx_destroy_image(var->mlx, var->e1.oneleft);
	if (var->e2.twoup)
		mlx_destroy_image(var->mlx, var->e2.twoup);
	if (var->e2.twodown)
		mlx_destroy_image(var->mlx, var->e2.twodown);
	if (var->e2.tworight)
		mlx_destroy_image(var->mlx, var->e2.tworight);
	if (var->e2.twoleft)
		mlx_destroy_image(var->mlx, var->e2.twoleft);
	if (var->e3.threeup)
		mlx_destroy_image(var->mlx, var->e3.threeup);
	if (var->e3.threedown)
		mlx_destroy_image(var->mlx, var->e3.threedown);
	if (var->e3.threeright)
		mlx_destroy_image(var->mlx, var->e3.threeright);
	if (var->e3.threeleft)
		mlx_destroy_image(var->mlx, var->e3.threeleft);
}

void	free_pokemon(t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->w_h.game[i])
		free (var->w_h.game[i++]);
	free (var->w_h.game);
	destroy_walls(var);
	destroy_other_component(var);
	destroy_player(var);
	destroy_enemies(var);
	if (var->mlx && var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	exit (0);
}
