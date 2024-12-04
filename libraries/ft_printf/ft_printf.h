/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:30:51 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/16 11:49:01 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_conversion(char c, va_list arg);
int	ft_print_pourcent(void);
int	ft_printf(const char *str, ...);
int	ft_putnbr_hexa(unsigned int n, char *base);
int	ft_putnbr_positiv(unsigned int n);
int	ft_memory_adress(void *ptr);
int	ft_putnbr(int n);

#endif
