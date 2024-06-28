/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:46:20 by mjadid            #+#    #+#             */
/*   Updated: 2024/06/28 02:32:54 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	send_char(char c, int pid);
void	ft_putnbr(int nbr);
void	signal_handler(int signal, siginfo_t *info, void *ptr);

#endif