#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <editline/readline.h>

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL; 
    return command;
    
}

int main() {
    char **command; 
    char *input;
    pid_t child_pid; 
    int stat_loc; 

    while(1) {
        input = readline("unixsh> ");
        command = get_input(input);

        child_pid = fork();

        if(child_pid == 0) {
            execvp(command[0], command);
            printf("This wont be printed if the execvp is successful");
        }
        else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;

}