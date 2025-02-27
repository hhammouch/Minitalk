/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:29:51 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/27 15:32:35 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	arg_error(void)
{
	char	*m;
	char	*ex;

	m = "\033[1;33mUsage:\033[0m \033[1;37m./client \033[1;36m<PID> <MESSAGE>";
	ex = "\n\033[1;32mExample:\033[0m ./client 12345 \"Hello, World!\n";
	ft_putstr("\033[1;31mError:\033[0m Invalid arguments.\n");
	ft_putstr(m);
	ft_putstr(ex);
}

void	valid_pid_error(int pid)
{
	char	*ex1;
	char	*ex2;
	char	*ht2;

	ex1 = "\033[1;32mExample:\033[0m ./program 12345 \"Hello, World!\"\n";
	ex2 = "\033[1;32mExample:\033[0m ./program 12345 \"Hello, World!\"\n";
	ht2 = "\033[1;33mHint:\033[0m PID must contain only digits (0-9).\n";
	if (pid < 0)
	{
		ft_putstr("\033[1;31mError:\033[0m Invalid PID.\n");
		ft_putstr("\033[1;33mHint:\033[0m PID must be a positive number.\n");
		ft_putstr(ex1);
	}
	else
	{
		ft_putstr("\033[1;31mError:\033[0m Invalid PID format.\n");
		ft_putstr(ht2);
		ft_putstr(ex2);
	}
}
