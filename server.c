/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:09:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/21 11:37:13 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char	c = 0;
	static int	bit = 0;
	printf("Received signal: %d, bit = %d, c = %c\n", signal, bit, c);
	if (signal == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;

	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}


int    main(void)
{
    struct sigaction    sa;

    ft_putstr("Server PID: ");
    ft_putnbr(getpid());
    write(1, "\n", 1);
    //initialize_signals();
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1,&sa, NULL);
    sigaction(SIGUSR2,&sa, NULL);
    while (1)
        pause();
    return (0);
}
