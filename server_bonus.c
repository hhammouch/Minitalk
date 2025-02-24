/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:09:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/24 13:38:43 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_clientpid = -1;

void	handle_bonus(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;

	(void)context;
	if (info->si_pid != g_clientpid)
	{
		bit = 0;
		c = 0;
		g_clientpid = info->si_pid;
	}
	c <<= 1;
	if (sig == SIGUSR1)
		c += 1;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(g_clientpid, SIGUSR2);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = &handle_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
