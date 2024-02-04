#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    if (argc < 3) {
        exit(1);
    }

    const char* outFile = argv[1];
    const char* cmd = argv[2];

    pid_t child_pid;
    int fd = open(outFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    child_pid = fork();

    if(child_pid == 0) {
        dup2(fd, 1);
        close(fd);
        execvp(cmd, &argv[2]);
    } else {
        close(fd);
    }


}

