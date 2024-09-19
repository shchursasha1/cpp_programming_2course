#include <stdio.h>

int main () {
    float T = 365 + 1 / (4 + (1 / (7 + (1 / (1 + 1 / 3)))));
    printf("T = %f\n", T);
}