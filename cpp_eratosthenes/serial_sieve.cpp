#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: <path_to_program> <int:test_space>\n");
        return 1;
    }
    unsigned long space = (unsigned long)strtol(argv[1], NULL, 10);
    bool* marked = (bool*)calloc(space, sizeof(bool));
    for (unsigned long i = 2; i < space; i++) {
        if (!marked[i]) {
            printf("%llu\n", i);
            for (unsigned long x = i * 2; x < space; x += i) {
                marked[x] = true;
            }
        }
    }
    return 0;
}

