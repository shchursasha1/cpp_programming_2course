#include <stdio.h>
#include <math.h>

void task13() {
    double r, R;
    printf("Enter the inner radius: ");
    scanf("%lf", &r);
    printf("Enter the outer radius: ");
    scanf("%lf", &R);

    double V = 2 * (M_PI *  M_PI) * R * (r * r);
    printf("Volume = %lf", V);
}


// 2.17 (є)
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double sigmoid_derivative(double x) {
    return sigmoid(x) * (1.0 - sigmoid(x));
}

int main() {
    double x;

    printf("Enter x: ");
    scanf("%lf", &x);

    double sig_value = sigmoid(x);
    double sig_derivative = sigmoid_derivative(x);

    printf("sigmoid = %lf\n", sig_value);
    printf("sigmoid_derivative = %lf", sig_derivative);

}