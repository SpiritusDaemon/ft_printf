/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarques <gmarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:21 by gmarques          #+#    #+#             */
/*   Updated: 2022/11/01 18:54:19 by gmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_putnbr_base2(long long n, int fd, char *base, long long size)
{
	int i;

	i = 0;
	if (n >= size || n <= -size)
		i += ft_putnbr_base2(n / size, fd, base, size);
	n %= size;
	n = ((n >= 0) - (n < 0)) * n;
	return (i + write(fd, &base[n], 1));
}

int	ft_putnbr_base(long long n, int fd, char *base, long long size)
{
	int i;

	i = 0;
	if (n < 0)
		i = write(fd, "-", 1);
	i += ft_putnbr_base2(n, fd, base, size);
	return (i);
}

int	receive_ptr(unsigned long n)
{
	int i;

	if (n == 0)
	{
		write(1, "(nil)", 6);
		return (0);
	}
	i = write(1, "0x", 2);

	i += ft_putnbr_base(n, 1, "0123456789abcdef", 16);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		;
	return (write(1, str, i));
}
