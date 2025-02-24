/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:14:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/24 15:06:59 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_bonus(int pid, char c)
{
	unsigned char	temp;
	int				i;

	temp = c;
	i = 8;
	while (i > 0)
	{
		i--;
		if (temp >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(800);
	}
}

int	_check_pid_(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	received_message(int sig)
{
	(void)sig;
	ft_putstr("\033[1;32mThe message was received\033[0m\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
	{
		arg_error();
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1 || _check_pid_(argv[1]))
	{
		valid_pid_error(pid);
		return (1);
	}
	sa.sa_handler = &received_message;
	sigaction(SIGUSR2, &sa, NULL);
	while (argv[2][i])
		handler_bonus(pid, argv[2][i++]);
	handler_bonus (pid, '\0');
	while (1)
		pause();
	return (0);
}
