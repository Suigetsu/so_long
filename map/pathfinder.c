/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:16:29 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/30 08:42:36 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

typedef struct s_wh
{
	int		w;
	int		h;
	int		i;
	int		j;
	void	*var;
	char	*map;
	char	**splited;
}				t_wh;


char	**mapreader(char *filename)
{
	int		fd;
	char	*s;
	t_wh	wh;
	
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	wh.h = 1;
	wh.w = ft_strlen(s) - 1;
	wh.map = ft_strdup(s);
	free (s);
	while (s)
	{
		s = get_next_line(fd);
		if (!s)
		{
			close (fd);
			free (s);
			break;
		}
		wh.map = ft_strjoin(wh.map, s);
		wh.h += 1;
	}
	wh.splited = ft_split(wh.map, '\n');
	free (wh.map);
	return (wh.splited);
}

void	startp(t_wh *var)
{
	var->i = 1;
	var->j = 1;
	// ft_printf("%d\n", var->w);
	while (var->i < var->h - 1)
	{
		while (var->j < var->w - 1)
		{
			if (var->splited[var->i][var->j] == 'P')
				ft_printf("%d, %d\n", var->i, var->j);
			var->j++;
		}
		var->i++;
	}
}

int	main()
{
	char	**s;
	t_wh	var;
	// mapreader("maptest.ber");
	startp(&var);
}

// int		pathfinder(t_vars *var, char **s)
// {	
// 	var->i = 0;
// 	var->j = 0;
	
	
// }
	