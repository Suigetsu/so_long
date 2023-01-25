/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:52:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	args_holder(va_list ap, char *format)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
	{
		count += ft_putchar('0');
		count += ft_putchar('x');
		count += ft_putadrs(va_arg(ap, unsigned long));
	}
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (*format == 'X')
		count += ft_putuphex(va_arg(ap, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += args_holder(ap, (char *)format);
			format++;
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(ap);
	return (count);
}
