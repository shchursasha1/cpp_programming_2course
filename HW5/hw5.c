#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

// task 5.12 (b)

double factorial(int n) {
    double result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}


void task12() {
    double ak_2 = 0, ak_1 = 1, ak, bk_2 = 1, bk_1 = 0, bk, sum = 0, u, v;
    int n;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter u: ");
    scanf("%lf", &u);
    printf("Enter v: ");
    scanf("%lf", &v);

    for (int k = 1; k <= n; k++ ) {
        if (k == 1) {
            ak = u;
            bk = v;
        } else {
            ak = 2 * bk_1 + ak_1;
            bk = 2 * pow(u, 2) + bk_1;
        }

        sum += (ak * bk) / factorial(k + 1);

        ak_2 = ak_1;
        ak_1 = ak;
        bk_2 = bk_1;
        bk_1 = bk;
    }

    printf("Sum: %lf\n", sum);
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
