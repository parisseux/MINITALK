/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:48 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/16 11:56:40 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_putnbr_hexa(unsigned int n, char *base)
{
	int		count;

	count = ft_count(n);
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 15)
	{
		ft_putnbr_hexa(n / 16, base);
		n %= 16;
	}
	if (n <= 15)
		write(1, &base[n], 1);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	int c = -234;
// 	printf("%d\n", printf("%x", c));
// 	printf("%d\n", ft_putnbr_hexa(c, "0123456789abcdef"));
// 	return (0);
// }