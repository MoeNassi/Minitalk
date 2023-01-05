/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:48:06 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/05 14:08:09 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	handle(int sig, siginfo_t *info, void *pnt)
{
	(void)pnt;
	static int c;
	static int bit;
	static int pid;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = c | 0 >> bit;
	if (sig == SIGUSR2)
		c = c | 128 >> bit;
	bit++;
	if (bit == 8)
	{
		write (1,&c,1);
		bit = 0;
		c = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	s;

	ft_putstr_fd("Here's the PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = handle;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
}
