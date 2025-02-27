/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:10:05 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/25 13:40:05 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(int n)
{
	long	nb;
	size_t	i;
	char	nbr[11];

	nb = n;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	i = 0;
	while (nb)
	{
		nbr[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	while (i > 0)
		write(1, &nbr[--i], 1);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	min;

	n = 0;
	i = 0;
	min = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		n = n * 10 + str[i++] - 48;
	if (min == 1)
		return (-n);
	else
		return (n);
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
