/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_positiv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:54:29 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/16 11:37:48 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_positiv(unsigned int n)
{
	unsigned int	count;

	if (n < 0)
		n *= -1;
	count = ft_count(n);
	while (n > 9)
	{
		ft_putnbr_positiv(n / 10);
		n %= 10;
	}
	if (n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	return (count);
}
