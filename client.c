/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:41:03 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/05 13:40:13 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

void	send(int pid, char c)
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
		usleep(500);
	}
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
