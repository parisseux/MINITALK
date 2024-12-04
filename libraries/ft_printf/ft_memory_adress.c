/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:20:56 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:01 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putnbr_hex(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_putnbr_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	ft_memory_adress(void *ptr)
{
	unsigned long	adress;
	int				count;

	count = 2;
	adress = (unsigned long) ptr;
	write(1, "0x", 2);
	if (!adress)
	{
		write(1, "0", 1);
		count += 1;
		return (count);
	}
	ft_putnbr_hex(adress);
	while (adress > 0)
	{
		adress /= 16;
		count++;
	}
	return (count);
}
