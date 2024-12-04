/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:45:21 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/04 16:48:45 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_message_confirmed = 0;

static int	ft_atoi_mt(const char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

static void	ft_confirm_reception(int signal)
{
	(void)signal;
	g_message_confirmed = 1;
	ft_printf("Confirmation: Message successfully received by the server.\n");
}

static void	ft_send_char(int server_pib, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x80 >> bit))
			kill(server_pib, SIGUSR1);
		else
			kill(server_pib, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pib;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pib = ft_atoi_mt(argv[1]);
	message = argv[2];
	signal(SIGUSR1, ft_confirm_reception);
	while (message[i])
	{
		ft_send_char(server_pib, message[i]);
		i++;
	}
	ft_send_char(server_pib, '\0');
	while (g_message_confirmed == 0)
		pause();
	g_message_confirmed = 0;
	return (0);
}
