#include <stdio.h>
#include <stdlib.h>

void sieve(int max_primes) {
    // Initialize sieve
    int* sieve = calloc(max_primes, sizeof(int));
    for (int i = 0; i < max_primes; i++) {
        sieve[i] = 1;
    }
    // Generate primes
    int num_primes = 0;
    for (int i = 2; i < max_primes; i++) {
        if (sieve[i] == 1) {
            // Print prime
            printf("%d\n", i);
            num_primes++;
            // Update sieve
            for (int j = i; j < max_primes; j += i) {
                sieve[j] = 0;
            }
            if (num_primes == max_primes) {
                break;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: <path_to_program> <int:test_space>\n");
        return 1;
    }
    unsigned long space = (unsigned long)strtol(argv[1], NULL, 10);
    sieve(space);
    return 0;
}
