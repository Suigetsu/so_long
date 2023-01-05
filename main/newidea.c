/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newidea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:48:47 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/30 15:46:06 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char    **map_read(t_vars *var)
{
	int     fd;
	char    *s;
	
	fd = open("map.ber", O_RDONLY);
	s = get_next_line(fd);
    var->w_h.width = ft_strlen(s) - 1;
    var->w_h.height = 1;
    var->w_h.map = ft_strdup(s);
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
        var->w_h.map = ft_strjoin(var->w_h.map, s);
        free (s);
        var->w_h.height += 1;
    }
    var->w_h.game = ft_split(var->w_h.map, '\n');
    free (var->w_h.map);
	return (var->w_h.game);
}

int	height_count(t_vars *var)
{
	int	i;
	char	**map;
	
	i = 0;
	map = map_read(var);
	while (map[i] != '\0')
		i++;
	return (i);
}

int	width_count(t_vars *var)
{
	int	j;
	int	i;
	char	**map;

	i = 0;
	j = 0;
	map = map_read(var);
	while (map[i][j] != '\0')
		j++;
	return (j);
}

int	coll_count(t_vars *var)
{
	int		count;
	
	var->i = 1;
	count = 0;
	var->w_h.game = map_read(var);
	var->w_h.height = height_count(var);
	var->w_h.width = width_count(var);
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while(var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'C')
				count += 1;
			var->j++;
		}
		var->i++;
	}
	return(count);
}

int	main()
{
	t_vars	var;
	int		i;
	int		j;

	i = coll_count(&var);
	ft_printf("%d\n", i);
}