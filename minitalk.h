/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:10:14 by hhammouc          #+#    #+#             */
/*   Updated: 2025/02/27 12:31:27 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

void	ft_putnbr(int n);
void	received_message(int sig);
void	recieved(int sig, siginfo_t *info, void *context);
void	ft_putstr(char *str);
void	arg_error(void);
void	valid_pid_error(int pid);
int		ft_atoi(const char *str);

void	handle_signals(int sig, siginfo_t *info, void *context);
void	handle_bonus(int sig, siginfo_t *info, void *context);
void	handler_bonus(int pid, char c);

#endif
