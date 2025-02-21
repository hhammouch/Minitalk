/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:06:14 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/15 18:43:26 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int sig)
{
	char	*c;

	c = "\nHey! I’m working here! You think a simple Ctrl+C can stop me?\n";
	if (sig == SIGINT)
		ft_putstr(c);
	else if (sig == SIGTERM)
		ft_putstr("\nHaha! Nice try... Just stay away from -9, okay? 👀\n");
	else if (sig == SIGQUIT)
		ft_putstr("\nRage quit detected! Did your keyboard survive?\n");
	else if (sig == SIGTSTP)
		ft_putstr("\nYou put me to sleep... but I dream of revenge!\n");
}

void	initialize_signals(void)
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	signal(SIGQUIT, handler);
	signal(SIGTSTP, handler);
}
