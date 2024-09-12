#include <stdio.h>
#include <math.h>

double Rosenbrock2D(double x, double y) {
    double t1 = pow(x, 2) - y;
    double t2 = x - 1;
    double z = 100 * pow(t1, 2) + pow(t2, 2);
    return z;
}

int main() {
    printf("%lf\n", Rosenbrock2D(3, 5));
    printf("%lf\n", Rosenbrock2D(1, 0));
    printf("%lf\n", Rosenbrock2D(4, 2));
}