#include <stdio.h>

void task1() {
    unsigned char n;
    printf("Input n: ");
    scanf("%hhu", &n);

    unsigned char result = (n << 1) | (n >> 7);

    printf("Result: %hhu\n", result);
}

void task2() {
    unsigned char n;
    printf("Input n: ");
    scanf("%hhu", &n);

    int zero_count = 0;

    for (int i = 0; i < 8; i++) {
        if ((n & (1 << i)) == 0) {
            zero_count++;
        }
    }

    printf("Amount of zeroes: %d\n", zero_count);
}


int main() {
    task1();
}
