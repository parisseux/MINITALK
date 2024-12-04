/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:28:22 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/15 16:47:31 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	sign;
	int	count;

	count = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count + sign);
}

int	ft_putnbr(int n)
{
	int	count;

	count = ft_count(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	while (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	return (count);
}
