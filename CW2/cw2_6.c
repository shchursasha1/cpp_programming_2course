#include <stdio.h>
#include <math.h>

double length(double x1, double x2, double y1, double y2) {
    double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double calculate_area(double A, double B, double C) {
    double p = (A + B + C) / 2;
    return sqrt(p * (p - A) * (p - B) * (p - C));
}

int main() {
    double ax, ay, bx, by, cx, cy;

    printf("Enter coordinates of A^ ");
    scanf("%lf % lf", &ax, &ay);

    getchar();

    printf("Enter coordinates of B ");
    scanf("%lf %lf", &bx, &by);

    getchar();

    printf("Enter coordinates of C ");
    scanf("%lf %lf", &cx, &cy);

    double A = length(ax, ay, bx, by);
    double B = length(bx, by, cx, cy);
    double C = length(cx, cy, ax, ay);

    double S = calculate_area(A, B, C);
    printf("The area is %lf\n", S);
}