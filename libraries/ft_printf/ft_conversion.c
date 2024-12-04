/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:54:39 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/16 11:52:12 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char c, va_list arg)
{
	int	n;

	n = 0;
	if (c == 'c')
		n += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		n += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		n += ft_memory_adress(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		n += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		n += ft_putnbr_positiv(va_arg(arg, unsigned int));
	else if (c == 'x')
		n += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		n += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		n += ft_print_pourcent();
	return (n);
}
