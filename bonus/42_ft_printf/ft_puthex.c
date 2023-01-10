/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:12:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/08 14:50:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (n > 0 && n <= 15)
		ft_putchar (str[n]);
	else
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
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
