/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:53:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:36 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
