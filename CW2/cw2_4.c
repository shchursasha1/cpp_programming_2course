#include <stdio.h>

double task4_e(double x) {
    double x2 = x * x;
    double x3 = x2 * x;
    double y = x3 * x2 + x; // should be x^5 + x^3 + x
    return y;
}

int main() {
    printf("Polynomial %lf", task4_e(1));
}
