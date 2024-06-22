/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:46 by mjadid            #+#    #+#             */
/*   Updated: 2024/06/21 16:00:47 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
    if(signal == SIGUSR1) {
        printf("Received signal 1 (SIGUSR1)\n");
    } else if(signal == SIGUSR2) {
        printf("Received signal 0 (SIGUSR2)\n");
    }
}

int main() {
    printf("PID: %d\n", getpid());

    // Register the signal handler for SIGUSR1 and SIGUSR2
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while(1) {
        pause(); // Wait for signals
    }

    return 0;
}