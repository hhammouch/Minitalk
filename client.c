/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:14:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:13 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void recieved(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static int	sent;

	if (sig == SIGUSR2)
		++sent;
}

void	handler(int pid, char c)
{
	unsigned char	temp;
	int				i;

	i = 8;
	temp = c;
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
		handler(pid, str[i++]);
	handler(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		arg_error();
		return (1);
	}
	sa.sa_sigaction = &recieved;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid < 1 || _check_pid_(argv[1]))
	{
		valid_pid_error(pid);
		return (1);
	}
	sent_msg(argv[2],pid);
	return (0);
}
