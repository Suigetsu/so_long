/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exitmeowth_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:49:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	meowth_rightexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j + 1] == 'M')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				free_pokemon(var);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	meowth_leftexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j - 1] == 'M')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				free_pokemon(var);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	meowth_upexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i - 1][var->j] == 'M')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				free_pokemon(var);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	meowth_downexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i + 1][var->j] == 'M')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				free_pokemon(var);
			}
			var->j++;
		}
		var->i++;
	}
}

void	meowth_exit(t_vars *var)
{
	meowth_downexit(var);
	meowth_upexit(var);
	meowth_leftexit(var);
	meowth_rightexit(var);
}
