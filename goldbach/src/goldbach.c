
#include <stdio.h>

/* Checks whether a number is prime */
int is_prime(long long n) {
    long long d;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    /* Test possible odd divisors */
    for (d = 3; d <= n / d; d += 2) {
        if (n % d == 0) {
            return 0;
        }
    }

    return 1;
}

/* Finds two prime numbers whose sum equals n */
void goldbach(long long n) {
    long long i, j;

    if (n <= 2 || n % 2 != 0) {
        printf("Goldbach's conjecture is only valid for even numbers greater than 2\n");
        return;
    }

    /* Search for the smallest possible first prime */
    for (i = 2; i <= n / 2; i++) {
        j = n - i;

        if (is_prime(i) && is_prime(j)) {
            printf("%lld = %lld + %lld\n", n, i, j);
            return;
        }
    }
}

int main(void) {
    long long n;
    char c;
    int r;

    while (1) {

        printf("Give me a number: ");
        fflush(stdout);

        r = scanf("%lld", &n);

        if (r == EOF) {
            printf("\nEOF detected, exiting\n");
            break;
        }

        /* Validate the number entered by the user */
        if (r != 1) {
            fprintf(stderr, "Invalid input: expected an integer\n");
            return 1;
        }

        if (n < 0 || n > 10000000000LL) {
            fprintf(stderr, "Number should be in the range [0, 10000000000]\n");
            return 1;
        }

        printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach) ", n);
        fflush(stdout);

        if (scanf(" %c", &c) != 1) {
            printf("\nEOF detected, exiting\n");
            break;
        }

        /* Read the selected operation */
        if (c != 'p' && c != 'g') {
            fprintf(stderr, "Invalid choice: expected 'p' or 'g'\n");
            return 1;
        }

        if (c == 'p') {
            if (is_prime(n)) {
                printf("%lld is prime\n", n);
            }
            else {
                printf("%lld is not prime\n", n);
            }
        }
        else if (c == 'g') {
            goldbach(n);
        }
    }

    return 0;
}

