/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarques <gmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:21 by gmarques          #+#    #+#             */
/*   Updated: 2022/11/06 13:22:21 by gmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_putnbr_base2(long long n, char *base, long long size)
{
	int	i;

	i = 0;
	if (n >= size || n <= -size)
		i += ft_putnbr_base2(n / size, base, size);
	n %= size;
	return (i + write(1, &base[n], 1));
}

int	ft_unsigned_base(unsigned int n, char *base, int size)
{
	int	i;

	i = 0;
	if (n >= size)
		i += ft_unsigned_base(n / size, base, size);
	n %= size;
	return (i + write(1, &base[n], 1));
}

int	ft_putnbr_base(long long n, char *base, long long size)
{
	int	i;

	i = 0;
	if (n < 0 && size != 16)
	{
		i = write(1, "-", 1);
		n *= -1;
	}
	i += ft_putnbr_base2(n, base, size);
	return (i);
}
