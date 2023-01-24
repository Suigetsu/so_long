/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:12:08 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
