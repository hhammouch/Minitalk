/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:10:14 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/21 11:31:19 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// #define _XOPEN_SOURCE 700

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

void    ft_putnbr(int n);
void    ft_putstr(char *str);
void    arg_error(void);
void    valid_pid_error(int pid);
int        ft_atoi(const char *str);
void    initialize_signals(void);

#endif