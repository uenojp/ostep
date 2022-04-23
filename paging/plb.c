#include <limits.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGESIZE 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: tlb <NUMPAGE>\n");
        exit(1);
    }

    char *endptr;
    const long numpage = strtol(argv[1], &endptr, 10 /* base */);
    if (!endptr || numpage < INT_MIN || INT_MAX < numpage) {
        fprintf(stderr, "failed to strtol: %s\n", argv[1]);
        exit(1);
    }
    const int jump = PAGESIZE / sizeof(int);
    int *const a = calloc(numpage * jump, sizeof(int));

    const double start = omp_get_wtime();
    for (int i = 0; i < numpage * jump; i += jump) {
        a[i] += i;
    }
    const double end = omp_get_wtime();
    printf("%ld %lf\n", numpage, (end - start) * 1000 * 1000);

    return 0;
}