#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2)
        return 1;

    size_t size = (size_t)atoi(argv[1]) * 1024 * 1024 * 1024; /* Gigabytes order */
    char* s = malloc(size);
    for (size_t i = 0; i < size; i++) {
        // ;  // <1>
        s[i] = 'a';  // <2>
    }

    return 0;
}
