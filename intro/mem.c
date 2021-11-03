#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

int main(int argc, char **argv) {
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("pid: %d, address: %p\n", getpid(), p);

    *p = 0;
    while(1) {
        Spin(1);
        *p = *p + 1;
        printf("pid: %d, p: %d\n", getpid(), *p);
    }
    return 0;
}