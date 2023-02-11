/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:29:49 by fgalan-n          #+#    #+#             */
/*   Updated: 2022/11/02 13:57:10 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[x])
	{
		ft_putchar(str[x]);
		x++;
	}
	return (x);
}

int	ft_int(int num)
{
	int		x;

	x = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}	
	else if (num > 9)
	{
		x += ft_int(num / 10);
		x += ft_int(num % 10);
	}
	else if (num < 0)
	{
		x += ft_putchar('-');
		x += ft_int(-num);
	}
	else
		x += ft_putchar(num + '0');
	return (x);
}

int	ft_unsigned_int(unsigned int long num)
{
	int	x;

	x = 0;
	if (num >= 10)
	{
		x += ft_unsigned_int(num / 10);
		x += ft_putchar("0123456789"[num % 10]);
	}
	else
		x += ft_putchar("0123456789"[num % 10]);
	return (x);
}
