/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:14:55 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/21 11:36:13 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int pid, char c)
{
	unsigned char	temp;
	int				i;

	i = 0;
	temp = c;
	while (i < 8)
	{
		if (temp << i & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(300);
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

int	main(int argc, char **argv)
{
	int	pid;
	int		i;

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
	while(argv[2][i])
	{
		handler(pid, argv[2][i]);
		i++;
	}
	return (0);
}
