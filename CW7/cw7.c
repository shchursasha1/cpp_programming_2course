#include <stdio.h>
#include <math.h>
#define SIZE 5
#define MAX_SIZE 50

int input_arr(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = ", i);
        int r = scanf("%d", &arr[i]);

        if (r != 1) {
            return i;
        }
    }
    return SIZE;
}

void output_arr(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void task1() {
    int array[SIZE] = {1, 2, 3, 4, 5};
    double number;
    unsigned count = 0;

    printf("Enter number: ");
    scanf("%lf", &number);

    for (int i = 0; i < SIZE; i++) {
        if (number > array[i]) {
            count++;
        }
    }

    printf("Number of elements that lesser than %3.lf: %d\n", number, count);
}

void task2() {
    int array[4] = {5, 112, 4, 3};
    double size = sizeof(array) / sizeof(array[0]);

    for (int i = size - 1; i >= 0; i--) {
        printf("%d, ", array[i]);
    }
}

double arr_sum(double arr[10]) {
    double sum = 0.0;

    for (int i = 0; i < 10; i++) {
        if (arr[i] > M_E) {
            sum += arr[i];
        }
    }

    return sum;
}

void task3() {
    double array[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter a %d element: ", i);
        scanf("%lf", &array[i]);
    }

    double sum = arr_sum(array);
    printf("Sum of elements that greater that e: %lf", sum);

}

void task4() {
    int array[SIZE];
    int max_value = 0;
    input_arr(array);

    for (int i = 0; i < SIZE; i++) {
        if (max_value < array[i]) {
            max_value = array[i];
        }
    }

    printf("Max value is %d\n", max_value);
}

void task5() {
    int p, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= MAX_SIZE) {
        int array[n] = {};
        for (int i = 0; i < n; i++) {
            scanf("%d", &p);
            array[i] = p;
        }
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        printf("Number of odd numbers: %d", odd);
        printf("Number of even numbers: %d", even);
    }
    else {
        printf("Number of elements should be less than 50.");
    }

}

void input_vector(double vec[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &vec[i]);
    }
}

void print_vector(int n, double vec[n]) {
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            printf("{%.0lf, ", vec[i]);
        }
        else if (i == n - 1) {
            printf(" %.0lf}\n", vec[i]);
        }
        else {
            printf("%.0lf, ", vec[i]);
        }
    }
}

void sum(int n, const double vec1[n], const double vec2[n], double vec3[]) {
    for (int i = 0; i < n; i++) {
        vec3[i] = vec1[i] + vec2[i];
    }
}

double scalar_product(int n, const double vec1[], const double vec2[]) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

void task6() {
    int n;
    double vec1[n], vec2[n], vec3[n];

    printf("Enter n: \n");
    scanf("%d", &n);

    input_vector(vec1, n);
    input_vector(vec2, n);

    printf("Vector 1 = ");
    print_vector(n, vec1);

    printf("Vector 2 = ");
    print_vector(n, vec2);

    sum(n, vec1, vec2, vec3);
    printf("Sum of vector 1 and vector 2 = ");
    print_vector(n, vec3);

    double scalar = scalar_product(n, vec1, vec2);
    printf("Scalar product = %.2lf", scalar);
}

int main() {
    task6();
}