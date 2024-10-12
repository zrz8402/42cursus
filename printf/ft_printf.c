/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:07:50 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/13 12:35:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_convert(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

int	parse_arg(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len = print_char(va_arg(args, int));
	else if (*format == 's')
		len = print_str(va_arg(args, char *));
	else if (*format == 'p')
		len = print_ptr(va_arg(args, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		len = print_int(va_arg(args, int));
	else if (*format == 'u')
		len = print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		len = print_hex(va_arg(args, unsigned int), *format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (to_convert("cspdiuxX", *format))
				count += parse_arg(format, args);
			else if (*format == '%')
				count += print_char('%');
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}
