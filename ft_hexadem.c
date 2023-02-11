/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:29:38 by fgalan-n          #+#    #+#             */
/*   Updated: 2022/11/02 11:35:33 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_transform(unsigned int long num, char *str)
{
	int	x;

	x = 0;
	if (num >= 16)
	{
		x += ft_transform(num / 16, str);
		x += ft_transform(num % 16, str);
	}
	else
		x += ft_putchar(str[num % 16]);
	return (x);
}

int	ft_hexadecimal(unsigned int num, char c)
{
	int	x;

	x = 0;
	if (c == 'x')
		x += ft_transform(num, "0123456789abcdef");
	else
		x += ft_transform(num, "0123456789ABCDEF");
	return (x);
}

int	ft_pointer(unsigned int long ptr)
{
	int	x;

	x = ft_transform(ptr, "0123456789abcdef");
	return (x);
}
