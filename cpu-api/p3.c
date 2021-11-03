#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Hello, World! (pid: %d)\n", getpid());
    int rc = fork();
    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid: %d)\n", getpid());
        char *myargs[4];
        myargs[0] = "wc";
        myargs[1] = "-l";
        myargs[2] = "p3.c";
        myargs[3] = NULL;
        execvp(myargs[0], myargs);
        printf("child: execvp failed\n");
    } else {
        int rc_wait = wait(NULL);
        printf("parent of %d (pid: %d)\n", rc, getpid());
    }
    return 0;
}