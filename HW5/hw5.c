#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

// task 5.12 (b)

long long factorial(int n) {
    double result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}


void task12() {
    int n;
    double u, v;
    double a_k, b_k;
    double a_prev1, a_prev2, b_prev1, b_prev2;
    double Sn = 0.0;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter u: ");
    scanf("%lf", &u);
    printf("Enter v: ");
    scanf("%lf", &v);

    a_k = u;
    b_k = v;
    a_prev1 = u;
    b_prev1 = v;

    for (int k = 1; k <= n; k++) {
        if (k > 1) {
            a_prev2 = a_prev1;
            b_prev2 = b_prev1;

            a_k = 2 * b_prev1 + a_prev2;
            b_k = 2 * a_prev1 * a_prev1 + b_prev2;

            a_prev1 = a_k;
            b_prev1 = b_k;
        }

        Sn += (a_k * b_k) / factorial(k + 1);
    }


    printf("Sum: %lf\n", Sn);
}


// task 5.16 (d)
void task16() {
    double sum = 1.0, term = 1.0, x;
    int n = 1;

    printf("Enter x: ");
    scanf("%lf", &x);

    while (fabs(term) >= EPSILON) {
        term *= x / n;
        sum += term;
        n++;
    }

    printf("Sum: %.7lf\n", sum);

}


int main() {
    task16();
}
