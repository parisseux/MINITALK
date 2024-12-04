/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:59:40 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/03 15:28:30 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	res;

	res = 0;
	count = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		count = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (count == 1)
		return (-res);
	return (res);
}

static void ft_send_char(int server_PIB, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (0x80 >> bit))
            kill(server_PIB, SIGUSR1);
        else 
            kill(server_PIB, SIGUSR2);
        bit++;
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    pid_t   server_PIB;
    char    *message;
    int i;

    if (argc != 3)
    {
        ft_printf("Usage: ./client <server_pid> <message>\n");
        return (1);
    }
    server_PIB = ft_atoi(argv[1]);
    message = argv[2];
    if (!server_PIB || !message)
    {
        ft_printf("Usage: ./client <server_pid> <message>\n");
        return (1);
    }
    i = 0;
    while (message[i])
    {
        ft_send_char(server_PIB, message[i]); 
        i++;
    }
    ft_send_char(server_PIB, '\0');
    return (0);
}
