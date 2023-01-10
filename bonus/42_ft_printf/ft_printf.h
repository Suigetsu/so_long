/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:09:49 by mlagrini          #+#    #+#             */
/*   Updated: 2022/10/24 19:51:18 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned int n);
int		ft_putuphex(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_putadrs(unsigned long n);

#endif
