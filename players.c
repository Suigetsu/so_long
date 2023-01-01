/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:33:27 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/31 19:47:34 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	g_count = 0;


char    **map_read2(t_vars *var)
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

int	count(t_vars *var)
{
	int		c;
	int		i;
	int		j;

	map_read(var);
	i = 0;
	c = 0;
	while (i < var->w_h.height)
	{
		j = 0;
		{
			while (j < var->w_h.width)
			{
				if (var->w_h.game[i][j] == 'C')
					c += 1;
				i++;
			}
			j++;
		}
	}
	return (c);
}

int	count2(char	**s)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if(s[i][j] == 'C')
				c += 1;
			j++;
		}
		i++;
	}
	return (c);
}

int	right(int key, t_vars *var)
{	
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' && var->w_h.game[var->i][var->j + 1] != '1')
			{
				if (var->w_h.game[var->i][var->j + 1] == 'C')
					g_count += 1;
				if (g_count % 2 == 0)
				{
					var->w_h.game[var->i][var->j] = '0';
					var->w_h.game[var->i][var->j + 1] = 'P';
					mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
    				mlx_put_image_to_window(var->mlx, var->win, var->p1.oneright1, (var->j + 1) * 64, var->i * 64);
					// rightmove1(var);
					break;
				}
			}
			var->j++;
		}
		var->i++;
	}
	return(0);
}

// int	main()
// {
// 	t_vars	var;
// 	int		i;
// 	char	**s;
// 	s = map_read2(&var);
// 	i = count2(s);
// 	ft_printf("%d\n", i);
// }
