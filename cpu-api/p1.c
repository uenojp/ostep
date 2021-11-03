#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("hello\n");
    int rc = fork();
    printf("world\n");
    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if (rc == 0) {
        printf("I'm child (pid: %d)\n", (int)getpid());
    } else {
        printf("I'm parent of %d (pid: %d)\n", rc, (int)getpid());
    }
    return 0;
}