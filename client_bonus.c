/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:14:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/27 12:33:36 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received_message(int sig)
{
	(void)sig;
	ft_putstr("\033[1;32mThe message was received\033[0m\n");
	exit(0);
}

void recieved_bonus(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static int	sent;

	if (sig == SIGUSR2)
		received_message(sig);
	else if (sig == SIGUSR1)
		++sent;
}

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
		pause();
		usleep(500);
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

void	sent_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		handler_bonus(pid, str[i++]);
	handler_bonus(pid, '\0');
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
	sa.sa_sigaction = &recieved_bonus;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sent_msg(argv[2],pid);
	return (0);
}
