/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:58 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/15 17:07:11 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		n;

	i = 0;
	n = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			n += ft_conversion(str[i], arg);
		}
		else
			n += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (n);
}
