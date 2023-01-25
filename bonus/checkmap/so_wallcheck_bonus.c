/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_wallcheck_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:30:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	upperwall(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	lowerwall(char	*filename)
{
	t_walls	var;

	var.c = 0;
	var.len = 0;
	var.fd = open(filename, O_RDONLY);
	var.s = get_next_line(var.fd);
	while (var.s)
	{
		free (var.s);
		var.s = get_next_line(var.fd);
		var.c += 1;
	}
	free (var.s);
	close (var.fd);
	var.fd = open(filename, O_RDONLY);
	while (var.len < var.c)
	{
		var.s = get_next_line(var.fd);
		var.len++;
		free (var.s);
	}
	var.c = upperwall(var.s);
	if (var.c <= 0)
		return (0);
	return (1);
}

int	wall_of_maria(char *filename)
{
	t_walls	var;

	var.fd = open(filename, O_RDONLY);
	var.s = get_next_line(var.fd);
	var.len = ft_strlen(var.s);
	var.c = upperwall(var.s);
	if (var.c <= 0)
		return (0);
	var.c = 0;
	while (var.s)
	{
		if (var.s[0] != '1' || var.s[var.len - 2] != '1')
		{
			free (var.s);
			return (0);
		}
		free (var.s);
		var.s = get_next_line(var.fd);
		var.c += 1;
	}
	free (var.s);
	var.c = lowerwall(filename);
	if (var.c <= 0)
		return (0);
	return (1);
}
