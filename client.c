#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>




int main(int argc , char **argv)
{
    int pid;
    int signal_number;

    pid = atoi(argv[1]);
    signal_number = atoi(argv[2]);

    while(1)
    {
         if(signal_number == 1) {
            kill(pid , SIGUSR1); // Send SIGUSR1 signal to the process
        } else if(signal_number == 0) {
            kill(pid , SIGUSR2); // Send SIGUSR2 signal to the process
        }
        // sleep(1);
    }
} 