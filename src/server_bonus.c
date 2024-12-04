/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:45:41 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/04 15:25:29 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server = {0, 0};

static void	ft_handle_signal(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		c = 0;

	(void)context;
	if (g_server.client_pid == 0 && info != NULL)
		g_server.client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (0x80 >> bit);
	else if (signal == SIGUSR2)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			g_server.message_complete = 1;
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_server.message_complete == 1)
		{
			ft_printf("\nMessage reçu. En attente d'un nouveau message...\n");
			kill(g_server.client_pid, SIGUSR1);
			g_server.message_complete = 0;
			g_server.client_pid = 0;
		}
	}
	return (0);
}
