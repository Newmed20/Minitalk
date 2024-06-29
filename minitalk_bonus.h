/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:58:48 by mjadid            #+#    #+#             */
/*   Updated: 2024/06/29 23:59:09 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	send_char(char c, int pid);
void	ft_putnbr(int nbr);
void	signal_handler(int signal, siginfo_t *info, void *ptr);

#endif