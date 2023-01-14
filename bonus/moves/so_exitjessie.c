/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exitjessie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:03:17 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/14 17:04:46 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	jessie_rightexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j + 1] == 'B')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	jessie_leftexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j - 1] == 'B')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	jessie_upexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i - 1][var->j] == 'B')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	jessie_downexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i + 1][var->j] == 'B')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

void	jessie_exit(t_vars *var)
{
	jessie_downexit(var);
	jessie_upexit(var);
	jessie_leftexit(var);
	jessie_rightexit(var);
}