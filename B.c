Q.2) Write a C program which creates a child process and child process catches a signal SIGHUP, SIGINT and SIGQUIT. The Parent process sends a SIGHUP or SIGINT signal after every 3 seconds, at the end of 15 seconds parent sends SIGQUIT signal to child and child terminates by displaying message "My Papa has Killed me!!!”.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    if (sig == SIGHUP) {
        printf("Child: Received SIGHUP\n");
    } else if (sig == SIGINT) {
        printf("Child: Received SIGINT\n");
    } else if (sig == SIGQUIT) {
        printf("Child: My Papa has Killed me!!!\n");
        exit(0);
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
       
        signal(SIGHUP, signal_handler);
        signal(SIGINT, signal_handler);
        signal(SIGQUIT, signal_handler);

        while (1) {
           
            pause();
        }
    } else if (pid > 0) {
        // Parent process sends signals
        sleep(3);
        kill(pid, SIGHUP); 
        sleep(3);
        kill(pid, SIGINT); 
        sleep(6);
        kill(pid, SIGQUIT); 
        wait(NULL);
    } else {
        perror("fork failed");
    }

    return 0;
}


Output:
Child: Received SIGHUP
Child: Received SIGINT
Child: My Papa has Killed me!!!