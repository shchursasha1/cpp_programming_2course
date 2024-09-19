#include <stdio.h>
#include <math.h>

int main() {
    float n;
    printf("Enter a number: ");
    scanf("%f", &n);

    float lg = log10(n);
    printf("log10 = %.3f\n", lg);
}