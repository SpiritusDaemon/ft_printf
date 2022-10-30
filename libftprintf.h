#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int ft_printf(const char *, ...);
static char *conv_char(char *str, char c);



#endif
