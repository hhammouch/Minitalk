/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:09:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:29 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;
	static int		current_pid;
	static int		client_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		bit = 0;
		c = 0;
		client_pid = current_pid;
	}
	c <<= 1;
	if (sig == SIGUSR1)
		c += 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	usleep(500);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = &handle_signals;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
		
	return (0);
}
