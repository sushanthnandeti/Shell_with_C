#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    pid_t child_pid;
    pid_t wait_result;
    int stat_loc;

    child_pid = fork();

    if (child_pid == 0) {
        printf("### child ### \n Current Pid : %d child Pid : %d \n", getpid(), child_pid);
        sleep(1);
    }
    else { 
        wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
        printf("### Parent ### \n Current Pid : %d and Child Pid : %d \n", getpid(), child_pid);
    }

    return 0;

}