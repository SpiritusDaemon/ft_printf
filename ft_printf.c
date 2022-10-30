#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int i;
	va_list arg;
	i = 0;
	va_start(arg, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c') /*single char*/
				conv_char((char)&str[i], (char)va_arg(arg, int));
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static char *conv_char(char *str, char c)
{
	int i;

	i = 0;
	str[i] = c;
	return (&str[i]);
}

int main(void)
{
	ft_printf("%c", 'a');
}
