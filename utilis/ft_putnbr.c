/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:10:10 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/13 21:11:43 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
