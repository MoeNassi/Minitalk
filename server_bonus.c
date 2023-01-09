/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:42:07 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/09 16:43:24 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk_tools/libft.h"
#include "minitalk.h"
#include <signal.h>

static void	handle(int sig, siginfo_t *info, void *param)
{
	static int	c;
	static int	bit;
	static int	pid;

	(void)param;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = c | 128 >> bit;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
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
