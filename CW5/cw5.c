#include <stdio.h>
#include <math.h>

void task_1a() {
    float a, sum = 0.0;
    int n = 1;
    printf("Enter a number: ");
    scanf("%f", &a);

    while (sum <= a) {
        sum += 1.0 / n;
        n++;
    }
    printf("The first number in the series greater that %.2f is %.6f\n", a, sum);
    printf("It occurs at n = %d\n", n - 1);
}

void task_1b() { // 1 + 1 / 2 + ... + 1 / n > a
    float a, sum = 0.0;
    int n = 1;

    printf("Enter a number: ");
    scanf("%f", &a);

    while (sum <= a) {
        sum += 1.0 / n;
        n++;
    }
    printf("The smallest n such that the sum is greater that %.2f is n = %d\n", a, n - 1);
}


// Функція для обчислення n-го числа Фібоначчі
int fibonacci_nth(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev1 = 1, prev2 = 0, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

// Функція для знаходження найбільшого числа Фібоначчі, що не перевищує a
int largest_fib_less_equal_than(int a) {
    int prev1 = 1, prev2 = 0, fib = 0, i = 1;

    while (fib <= a) {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
        i++;
    }

    return i - 2; // Повертаємо індекс попереднього числа
}

// Функція для знаходження найменшого числа Фібоначчі, що більше за a
int smallest_fib_greater_than(int a) {
    int prev1 = 1, prev2 = 0, fib = 0, i = 1;

    while (fib <= a) {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
        i++;
    }

    return i - 1;
}

// Функція для знаходження суми всіх чисел Фібоначчі, що не перевищують 1000
int sum_fibs_up_to_1000() {
    int prev1 = 1, prev2 = 0, fib = 0, sum = 1;

    while (fib <= 1000) {
        fib = prev1 + prev2;
        if (fib > 1000) break;
        sum += fib;
        prev2 = prev1;
        prev1 = fib;
    }

    return sum;
}

void task2() {
    int n, a;

    printf("Enter n to compute F(n): ");
    scanf("%d", &n);
    printf("F(%d) = %d\n", n, fibonacci_nth(n));

    printf("Enter a to find largest F(k) <= a: ");
    scanf("%d", &a);
    printf("Largest F(k) such that F(k) <= %d is F(%d)\n", a, largest_fib_less_equal_than(a));

    printf("Enter a to find smallest F(k) > a: ");
    scanf("%d", &a);
    printf("Smallest F(k) such that F(k) > %d is F(%d)\n", a, smallest_fib_greater_than(a));

    printf("Sum of Fibonacci numbers up to 1000 is %d\n", sum_fibs_up_to_1000());

}

int count_steps_to_one(int n) {
    int steps = 0;

    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        steps++;
    }

    return steps;
}

int find_max_steps_under_1000() {
    int max_steps = 0, number_with_max_steps = 0;

    for (int i = 1; i < 1000; i++) {
        int steps = count_steps_to_one(i);
        if (steps > max_steps) {
            max_steps = steps;
            number_with_max_steps = i;
        }
    }

    return number_with_max_steps;
}


void task3() {
    unsigned n;

    printf("Enter n: ");
    scanf("%u", &n);

    int steps = count_steps_to_one(n);
    printf("Number of steps for %u to reach 1: %d\n", n, steps);

    int number_with_max_steps = find_max_steps_under_1000();
    printf("Number with max steps under 1000: %d\n", number_with_max_steps);

}

void task4_a() { // product (1 + 1/i!)
    unsigned n;
    double P = 1, P_k, a_k = 1;

    printf("Enter n: ");
    scanf("%u", &n);

    for (int i = 1; i <= n; i++) {
        a_k = a_k / i;
        P_k = P * (1 + a_k);
        P = P_k;
    }

    printf("Result = %.2lf\n", P_k);
}

void task4_b() {
    unsigned n;
    double P = 1, P_k, a_k;

    for (int i = 1; i <= n; i++) {
        a_k = pow(-1, i + 1) * pow(i, 2) / pow(2, i);
        P_k = P * (1 + a_k);
        P = P_k;
    }

    printf("Result = %.2lf\n", P_k);
}

void task5() {
    int x1 = -99, x2 = -99, x3 = -99, x;
    int i = 3;

    while (x < 0) {
        x = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        i++;
    }
    printf("x(%d) = %d", i, x);
}

double task6_a(int n, double b) {
    double result = b;

    for (int i = 1; i <= n; i++) {
        result = b + 1.0 / result;

    }

    return result;
}

double task6_b(int n) {
    double result = 10.0;

    for (int i = n - 1; i >= 0; i--) {
        result = 4 * i + 6 + 1.0 / result;
    }

    return 2.0 + 1.0 / result;
}

double task6_c(int n) {
    double result = 1.0 / 2.0;

    for (int i = 1; i <= n; i++) {
        result = 1.0 / (1 + result);

    }

    return 1.0 + result;
}

void task6() {
    int n;
    double b;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Task 6 (a) = %lf", task6_a(n, b));
    printf("\n Task 6 (b) = %lf", task6_b(n));
    printf("\n Task 6 (c) = %lf", task6_c(n));
}


double calculate_sum(int n) {
    double ak_2 = 0, ak_1 = 1, ak, bk_2 = 1, bk_1 = 0, bk, sum = 0;

    for (int k = 1; k <= n; k++) {
        if (k == 1) {
            ak = 0;
            bk = 1;
        } else if (k == 2) {
            ak = 1;
            bk = 0;
        } else {
            ak = (ak_1 + ak_2 * bk_1) / k;
            bk = bk_1 + ak_1;
        }

        sum += (1 << k) / (ak + bk);

        ak_2 = ak_1;
        ak_1 = ak;
        bk_2 = bk_1;
        bk_1 = bk;
    }

    return sum;
}


void task7() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("S_n = %lf\n", calculate_sum(n));
}


double exp_taylor(double x, double eps) {
    double term = 1, sum = 1;
    int n = 1;

    while (fabs(term) > eps) {
        term *= x / n;
        sum += term;
        n++;
    }

    return sum;
}


double phi_taylor(double x, double eps) {
    double term = x, sum = x;
    int n = 1;

    while (fabs(term) > eps) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}


void task8() {
    double x, eps;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    printf("e^x (Taylor) = %lf\n", exp_taylor(x, eps));
    printf("e^x (math.h) = %lf\n", exp(x));

    printf("Phi(x) = %lf\n", phi_taylor(x, eps));
    printf("exp(-x^2) = %lf\n", exp(-1 * pow(x, 2)));
}

int main() {
    task8();
}