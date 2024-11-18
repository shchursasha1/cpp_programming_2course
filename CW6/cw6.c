#include <stdio.h>
#include <math.h>

void task1() {
    int n;

    printf("Enter an 8-bit natural number (n < 64): ");
    scanf("%d", &n);

    if (n < 1 || n >= 64) {
        printf("Error: The number must be a natural number less than 64.\n");
    }

    int result = 1 << n;

    printf("The result is: %d\n", result);
    printf("The number is: %d\n", (n >> 31) & 1);
}

void task2() {
    int n;
    unsigned k;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    int result = n | (1 << k);

    printf("The result is: %d\n", result);
}


void task3() {
    unsigned long long m;
    unsigned j;

    printf("Enter m: ");
    scanf("%llu", &m);
    printf("Enter j: ");
    scanf("%u", &j);

    printf("%llu", m &~(1 << j));

}

void task4() {
    unsigned n;

    printf("Enter n: ");
    scanf("%u", &n);

    unsigned b1 = n & 0xFF;
    unsigned b2 = (n >> 8) & 0xFF;
    unsigned b3 = (n >> 16) & 0xFF;
    unsigned b4 = n >> 24;
    unsigned m = (b1 << 24) | (b3 << 16) | (b2 << 8) | b4;

    printf("%u", m);
}


void task5() {
    unsigned long long number;

    printf("Enter a number: ");
    scanf("%lf", &number);

    unsigned max_count = 0;

    while (number) {
        unsigned count = 0;

        while (number & 1) {
            number >>= 1;
            count++;
        }

        number >>= 1;

        if (max_count < count) {
            max_count = count;
        }
    }

    printf("%u", max_count);
}

int divisor2(unsigned n) {
    int k = 1;
    while (n % k == 0) {
        k *= 2;
    }
    return k;
}


void task6() {
    unsigned long long x;
    printf("Enter a number: ");
    scanf("%llu", &x);

    /*for (unsigned i = 0; i < 1 << 32 - 1; i++) {
        if(!(i & (i - 1))) {
            printf("%u\t", i);
        }
     }*/

    for (unsigned i = 0; i < 1 << 32 - 1; ++i) {
        if (divisor2(i) != -i & i) {
            printf("%u - not work", i);
        }
    }
}

const char* task7() {
    unsigned num = 1;
    char *byte_ptr = (char*) & num;

    if (byte_ptr[0] == 1) {
        return "Little-endian";
    }
    else if (byte_ptr[-1] == 1) {
        return "Big-endian";
    }
    return 0;
}

int main() {
    printf("The architecture is %s", task7());
}
