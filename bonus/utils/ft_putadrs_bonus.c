/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:48:53 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putadrs(unsigned long n)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (n > 0 && n <= 15)
		ft_putchar (str[n]);
	else
	{
		ft_putadrs(n / 16);
		ft_putadrs(n % 16);
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
