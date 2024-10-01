#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6

// 4.18 (ж)
void task18() {
    double power = 1.0, x;
    int sign = 1, k;
    unsigned long long factorial = 1;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter k: ");
    scanf("%d", &k);

    if (k % 2 != 0) {
        sign = -1;
    }

    for (int i = 1; i <= 2*k+1; i++) {
        power *= x;          // x^(2k+1)
        factorial *= i;      // (2k+1)!
    }

    double result = (sign * power) / factorial;
    printf("%lf\n", result);
}


// 4.27 (є)
void task27() {
    double sum = 0.0, term;
    int k = 0;

    do {
        term = pow(-1, k) / pow(16, k) *
               (8.0 / (8 * k + 2) +
                4.0 / (8 * k + 3) +
                4.0 / (8 * k + 4) -
                1.0 / (8 * k + 7));

        sum += term;
        k++;
    } while (fabs(term) > EPSILON);

    printf("Approximated value of pi: %.15f\n", sum / 2);

}


int main() {
    task27();
}
