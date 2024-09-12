#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    float p = (a + b + c) / 2;

    if (a + b > c && b + c > a && c + a > b) {
        float S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%f\n", S);
    }
}