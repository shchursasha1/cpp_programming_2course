// 5 (b)

#include <stdio.h>

int main() {
    float x;
    printf("Enter x: ");
    scanf("%f", &x);

    float x_2  = x * x;
    float x_6 = x_2 * x_2;
    printf("The result is %f\n", x_6);
}