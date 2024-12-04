/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:59:32 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/04 15:24:48 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_message_complete = 0;

static void	ft_handle_signal(int signal)
{
	static int		bit = 0;
	static char		c = 0;

	if (signal == SIGUSR1)
		c |= (0x80 >> bit);
	else if (signal == SIGUSR2)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			g_message_complete = 1;
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
	{
		pause();
		if (g_message_complete == 1)
		{
			ft_printf("\nMessage reçu. En attente d'un nouveau message...\n");
			g_message_complete = 0;
		}
	}
	return (0);
}
