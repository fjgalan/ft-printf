/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:30:00 by fgalan-n          #+#    #+#             */
/*   Updated: 2022/11/02 13:34:44 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char *str, int i, va_list *ap)
{
	int	x;

	x = 0;
	if (str[i] == 'c')
		x += ft_putchar((char)va_arg(*ap, int));
	else if (str[i] == '%')
		x += ft_putchar('%');
	else if (str[i] == 's')
		x += ft_putstr(va_arg(*ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		x += ft_int(va_arg(*ap, int));
	else if (str[i] == 'u')
		x += ft_unsigned_int(va_arg(*ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		x += ft_hexadecimal(va_arg(*ap, unsigned int), str[i]);
	else if (str[i] == 'p')
	{
		x += ft_putstr("0x");
		x += ft_pointer(va_arg(*ap, unsigned int long));
	}	
	return (x);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	args;

	i = 0;
	x = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			x += ft_check(str, i, &args);
		}
		else
			x += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (x);
}
