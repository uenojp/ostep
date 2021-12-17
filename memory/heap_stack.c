#include <stdio.h>
#include <stdlib.h>

int non_init;
int init = 2;

int main(int argc, char **argv) {
    printf("initialized global: %p\n", &init);
    printf("non initialized global: %p\n", &non_init);
    printf("code:  %p\n", main);
    printf("argv:  %p\n", argv);
    printf("heap:  %p\n", malloc(10e6));
    int x = 3;
    printf("stack: %p\n", &x);

    return 0;
}