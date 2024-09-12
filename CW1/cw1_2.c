#include <stdio.h>
#include <math.h>

int main() {
    float num1 = 10e-4;
    printf("%.2f\n", num1);

    double num2 = 24.33E5;
    printf("%.2f\n", num2);

    long double num3 = M_PI;
    printf("%.2f\n", num3);

    long double num4 = M_E;
    printf("%.2f\n", num4);

    double num5 = sqrt(5);
    printf("%.2f\n", num5);

    double num6 = log(100);
    printf("%.2f\n", num6);

}