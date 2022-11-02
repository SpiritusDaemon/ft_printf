/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarques <gmarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:51 by gmarques          #+#    #+#             */
/*   Updated: 2022/11/02 22:06:49 by gmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cases(va_list arg, char *str, int i)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (str[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str[i] == 'p')
		return (receive_ptr(va_arg(arg, long long)));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789", 10));
	if (str[i] == 'u')
		return (ft_putnbr_base(va_arg(arg, unsigned long), "0123456789", 10));
	if (str[i] == 'x')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789abcdef", 16));
	if (str[i] == 'X')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789ABCDEF", 16));
	if (str[i] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		size;

	i = -1;
	size = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && ++i)
			size += ft_cases(arg, (char *)str, i);
		else
			size += ft_putchar(str[i]);
	}
	return (size);
}

/* int main(void)
{
	void *ptr = NULL;
	int *x = 0;
	int *e = 0;
	int i = ft_printf("\nmy func = %p %p", x, e);
	int i_printf;
	i_printf = printf("\noriginal func = %p %p", x, e);
	printf("\nmy func:%d\noriginal func:%d\n", i, i_printf);
} */
