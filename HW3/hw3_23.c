#include <stdio.h>

double ReLu(double x) {
    if (x < 0) {
        x = 0;
        return x;
    }

    return x;
}

int ReLu_derivative(double x) {
    x = 0; // derivative of a constant equals zero
    return x;
}

int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Result = %.1f\n", ReLu(x));
    printf("Derivative = %.1d\n", ReLu_derivative(ReLu(x)));
}