/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exitgiovanni.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:09:42 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 22:45:28 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	giovanni_rightexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j + 1] == 'G')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	giovanni_leftexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j - 1] == 'G')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	giovanni_upexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i - 1][var->j] == 'G')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	giovanni_downexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i + 1][var->j] == 'G')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

void	giovanni_exit(t_vars *var)
{
	giovanni_downexit(var);
	giovanni_upexit(var);
	giovanni_leftexit(var);
	giovanni_rightexit(var);
}
