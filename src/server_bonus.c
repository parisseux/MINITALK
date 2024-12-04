/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:45:41 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/03 15:45:43 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

static volatile sig_atomic_t message_complete = 0;

static void ft_handle_signal(int signal)
{
    static int bit = 0;
    static unsigned char c = 0;

    if (signal == SIGUSR1)
        c |= (0x80 >> bit);
    else if (signal == SIGUSR2)
        c &= ~(0x80 >> bit);
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
            message_complete = 1;
		write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}
int main(int argc, char **argv)
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
        if (message_complete == 1)
        {
            ft_printf("\nMessage reçu. En attente d'un nouveau message...\n");
            message_complete = 0;
        }
    }
	return (0);
}
