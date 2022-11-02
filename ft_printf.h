/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarques <gmarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:06:35 by gmarques          #+#    #+#             */
/*   Updated: 2022/11/02 22:06:57 by gmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
static char		*conv_char(char *str, char c);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr_base(long long n, char *base, long long size);
int				receive_ptr(long long n);
#endif
