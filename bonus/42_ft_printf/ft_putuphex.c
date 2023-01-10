/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:50:16 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/08 14:51:27 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned int n)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789ABCDEF";
	if (n > 0 && n <= 15)
		ft_putchar (str[n]);
	else
	{
		ft_putuphex(n / 16);
		ft_putuphex(n % 16);
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
