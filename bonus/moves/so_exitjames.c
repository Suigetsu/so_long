/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exitjames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:20:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/14 16:58:40 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	james_rightexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j + 1] == 'A')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	james_leftexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i][var->j - 1] == 'A')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	james_upexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i - 1][var->j] == 'A')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

static void	james_downexit(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && \
				var->w_h.game[var->i + 1][var->j] == 'A')
			{
				ft_printf("You lost :(( Better luck next time!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
}

void	james_exit(t_vars *var)
{
	james_downexit(var);
	james_upexit(var);
	james_leftexit(var);
	james_rightexit(var);
}