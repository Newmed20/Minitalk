/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:05 by mjadid            #+#    #+#             */
/*   Updated: 2024/06/27 12:11:44 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_atoi(char *str)
{
    int result = 0;
    int signe = 1;
    int i =0;

    while(((str[i] >= 9 & str[i] <= 13)||str[i] == 32) && str[i])
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            signe  *= -1;
        i++;
    }
    while(str[i])
    {
        result = result*10 + (str[i] - '0');
        i++;
    }
    return(result*signe);
}

void    send_char(char c , int pid)
{
    int i = 7;
    while(i>= 0)
    {
        if((c >> i)& 1)
            kill(pid , SIGUSR1);
        else
            kill(pid , SIGUSR2);
        usleep(200);
        i--;   
    }
    
}

int main(int argc , char **argv)
{
    int pid;
    int i = 0;

    pid = ft_atoi(argv[1]);

    if(argc == 3 && pid > 0)
    {
        while(argv[2][i])
        {
            send_char(argv[2][i] , pid);
            i++;
        }
        send_char('\0' , pid);
    }
    
    return 0;
} 