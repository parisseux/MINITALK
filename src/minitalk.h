/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:06:19 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/04 15:46:16 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include  <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_server {
	pid_t		client_pid;
	int			message_complete;
}	t_server;

#endif 