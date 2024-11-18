#include <stdio.h>
#include <limits.h>

// task 7.9 (д)
int task9() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n < 4) {
        printf("The number of elements must be at least 4.\n");
        return 1;
    }

    double a[n];
    printf("Enter %d real numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // Пошук min(a2, a4, ...)
    double min_even_index = a[1];
    for (int i = 3; i < n; i += 2) { // Цикл по парних індексах: a4, a6, ...
        if (a[i] < min_even_index) {
            min_even_index = a[i];
        }
    }

    // Пошук max(a1, a3, ...)
    double max_odd_index = a[0]; // Індекс a1 = 0
    for (int i = 2; i < n; i += 2) { // Цикл по непарних індексах: a3, a5, ...
        if (a[i] > max_odd_index) {
            max_odd_index = a[i];
        }
    }

    double result = min_even_index + max_odd_index;
    printf("Result min(a2, a4, ...) + max(a1, a3, ...): %.2lf\n", result);

    return 0;
}

// task 7.10 (б)
int task10() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("The number of elements must be at least 2.\n");
        return 1;
    }

    int a[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int min_sum = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        int sum = a[i] + a[i + 1];
        if (sum < min_sum) {
            min_sum = sum;
        }
    }

    printf("Result: %d\n", min_sum);
    return 0;
}

int main() {
}
