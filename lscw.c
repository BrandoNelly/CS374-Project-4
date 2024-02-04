#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

    const char *directory = (argc == 2) ? argv[1] : ".";

    int fd[2];
    pid_t child_pid;

    pipe(fd);


    child_pid = fork();

    if(child_pid == 0) {
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("wc", "wc", "-l", (char *)NULL);
        exit(0);
    } else {
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("ls", "ls", "-1a", directory, (char *)NULL);
        exit(0);
    }

}