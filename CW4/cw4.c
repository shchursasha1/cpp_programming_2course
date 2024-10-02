#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

void task1() {
    double x, y;
    unsigned int n;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter n: ");
    scanf("%u", &n);

    y = x;

    for (int i = 0; i <= n; i++) {
        y = sin(y);
    }
    printf("y = %lf", y);

}


void task2() {
    unsigned n;
    printf("Enter n: ");
    scanf("%u", &n);

    printf("n! = ");
    for (int i = 1; i <= n; i++) { // цикл по діапазону зі зростанням
        printf("%u*", i);
    }
    printf("...*n\n");

    printf("n! = ");
    for (int i = n; i >= 1; i--) { // цикл по діапазону зі спаданням
        printf("%u*", i);
    }
    printf("...*n\n");
}


// 3 (b)
void task3() {
    double x, y;
    double result = 0;
    int n;

    printf("Enter x, y: ");
    scanf("%lf %lf", &x, &y);
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        result += pow(x, pow(2, n - i)) * pow(y, n - i);
    }
    printf("result = %lf", result);
}


void task4() {
    unsigned n;
    double x, result = 0;

    printf("Enter n: ");
    scanf("%u", &n);
    printf("Enter x: ");
    scanf("%lf", &x);

    for (unsigned i = 1; i <= n; i++) {
        result += i * pow(x, i);
    }
    printf("result = %lf", result);
}

void task5() {
    unsigned long long n, fact = 1;

    printf("Enter n: ");
    scanf("%u", &n);

    if (n % 2 == 0) {
        for (int i = 2; i <=n; i+= 2) {
            fact *= i;
        }
    }
    else {
        for (int i = 1; i <=n; i+= 2) {
            fact *= i;
        }
    }

    printf("n!! = %llu", fact);
}


void task6_a() {
    unsigned n;
    double res = 0;

    printf("Enter n: ");
    scanf("%u", &n);

    for (int i = 0; i < n; i++) {
        res = sqrt(2 + res);
    }

    printf("Result = %lf", res);
}


void task6_b() {
    unsigned n;
    double res = 0;

    printf("Enter n: ");
    scanf("%u", &n);

    for (int i = 0; i < n; i++) {
        res += sqrt(3 * (n - i));
    }

    printf("Result = %lf", res);
}


void task7() {
    int n;
    double x, res = 1, add = 1;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%lf", &x);

    if (n == 0) {
        printf("Result = 1");
    }

    for (int i = 1; i <= n; i++) {
        add *= (x / i);
        res += add;
    }

    printf("Result = %.3lf", res);
}


void task8() {
    unsigned long long m; // m >= 1
    int k = 0;

    printf("Enter m (m >= 1): ");
    scanf("%llu", &m);

    if (m < 1) {
        printf("Error! must be greater than one\n");
        exit(1);
    }

    while (pow(4, k) <= m) {
        k++;
    }

    printf("The largest integer k such that 4^k <= %llu is: %d\n", m, k - 1);

}


void task9() {
    unsigned long long n, r = 0, power_of_two = 1;

    printf("Enter n: ");
    scanf("%llu", &n);

    do {
        r++;
        power_of_two *= 2;
    }
    while (power_of_two <= n);

    printf("The smallest 2^r that exceeds %llu is: 2^%llu = %llu\n", n, r, power_of_two);
}


void task10() {
    double a = 1;

    do {
        a /= 2;
    } while (a + 1 != 1);

    printf("Machine zero = %.10lf", a);
}


void task11() {
    int i = 0;
    double x, sum = 0, product = 1.0;
    double eps = DBL_EPSILON * 2;

    do {
        printf("a[%d] =", i);
        scanf("%lf", &x);

        if (fabs(x) > eps) {
            sum += x;
            product *= x;
            i++;
        }
    } while (fabs(x) > eps);

    if (i > 0) { // check if numbers were entered
        double geometric_mean = pow(product, 1.0 / i);

        printf("Sum = %lf", sum);
        printf("\n Arithmetic average = %lf", sum / i);
        printf("\n Geometric average = %lf", geometric_mean);

    } else {
        printf("Nu numbers were entered. \n");
    }
}


void task12() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("!0 = 1");
    }
    else if (n == 1) {
        printf("!1 = 0");
    }

    unsigned long long perv1 = 1, perv2 = 0, result = 0;

    for (int i = 2; i <= n; i++) {
        result = (i - 1) * (perv2 + perv1);
        perv1 = perv2;
        perv2 = result;
    }
    printf("!%d = %llu", n, result);
}

int main() {
    task12();
}