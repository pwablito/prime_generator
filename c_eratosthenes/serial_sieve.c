#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: <path_to_program> <int:test_space>\n");
        return 1;
    }
    unsigned long space = (unsigned long)strtol(argv[1], NULL, 10);
    unsigned long sqrt_space = (unsigned long)sqrt(space);
    bool* marked = (bool*)calloc(space, sizeof(bool));
    for (unsigned long i = 2; i < sqrt_space; i++) {
        if (!marked[i]) {
            for (unsigned long x = i * i; x < space; x += i) {
                marked[x] = true;
            }
        }
    }
    for (unsigned long i = 2; i < space; i++) {
        if (!marked[i]) {
            printf("%lu\n", i);
        }
    }
    return 0;
}

