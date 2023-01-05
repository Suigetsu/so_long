/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:14:50 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/30 10:20:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

typedef struct s_errors
{
    char    *inv_char;
    char    *rect_map;
    char    *map_name;
    char    *map_wall;
}				t_errors;


void    validmap(char  *filename)
{
    int     	i;
    t_errors	*s;
    
	s->inv_char = "Error\nInvalide/missing characters";
	s->map_wall = "Error\nMap is not surrounded with walls";
	s->rect_map = "Error\nMap is not rectangle";
	s->map_name = "Error\nMap's name is not valid";
    i = mapchars(filename);
    if (i <= 0)
		ft_printf("%s\n", s->inv_char);
	i = wall_of_maria(filename);
	if (i <= 0)
		ft_printf("%s\n", s->map_wall);
	i = maprectangle(filename);
	if (i <= 0)
		ft_printf("%s\n", s->rect_map);
	i = mapname(filename);
    if (i != 0)
		ft_printf("%s\n", s->map_name);
}

int	main()
{
    validmap("maptest.ber");
}