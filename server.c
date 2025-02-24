/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:09:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/23 18:09:25 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int sig)
{
	static int		bit;
	static char		c;

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
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
