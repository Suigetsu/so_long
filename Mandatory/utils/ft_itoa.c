/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:33:47 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	digitcount(int nbr)
{
	int			count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static void	digits(long long n, char *s)
{
	int			i;

	i = 0;
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
}

static char	revprint(char *s)
{
	int			len;
	int			i;
	int			c;

	i = 0;
	len = ft_strlen(s);
	while (len-- && i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
	}
	return (s[i]);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			n_len;
	long long	b;

	n_len = digitcount(n) + 1;
	b = n;
	if (n < 0)
	{
		b = -b;
		n_len++;
	}
	s = malloc (n_len * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[n_len - 1] = 0;
	s[n_len - 2] = '-';
	if (b == 0)
		s[0] = '0';
	digits(b, s);
	revprint(s);
	return (s);
}
