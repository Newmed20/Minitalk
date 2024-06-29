/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:46 by mjadid            #+#    #+#             */
/*   Updated: 2024/06/29 23:59:40 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 0 && nbr <= 9)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	signal_handler(int signal, siginfo_t *info, void *ptr)
{
	static int	pid;
	static char	c;
	static int	i = 7;

	(void)ptr;
	if (pid != info->si_pid)
	{
		c = 0;
		i = 7;
		pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		c |= 1 << i;
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(pid, SIGUSR1);
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	write(1, "PID OF SERVER IS : ", 20);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
