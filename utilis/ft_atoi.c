/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:33:56 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/19 21:12:39 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
