/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:42:21 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/17 12:26:06 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "Minitalk_tools/libft.h"
#include "minitalk.h"

static void	send(int pid, char c)
{
	int		i;
	int		bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i & 1);
		if (bit == 1)
			kill(pid, SIGUSR2);
		else if (bit == 0)
			kill(pid, SIGUSR1);
		usleep(400);
	}
	usleep(400);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		while (av[2][i])
			send(pid, av[2][i++]);
		write(1, "\n", 1);
	}
	return (0);
}
