/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-n <fgalan-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:30:08 by fgalan-n          #+#    #+#             */
/*   Updated: 2022/11/02 11:33:56 by fgalan-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_int(int num);
int	ft_unsigned_int(unsigned int long num);
int	ft_hexadecimal(unsigned int num, char c);
int	ft_pointer(unsigned int long ptr);
int	ft_printf(const char *str, ...);

#endif
