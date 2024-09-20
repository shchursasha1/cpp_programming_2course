#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task1() {
    unsigned num1;
    unsigned a, b, c, sum, inverted;

    printf("Enter the number: ");
    scanf("%u", &num1);

    if (num1 >= 100 && num1 <= 999) {
        a = num1 % 10;
        b = (num1 / 10) % 10;
        c = num1 / 100;

        printf("%u%u%u\n", a, b, c);
        sum = a + b + c;
        printf("%u\n", sum);
        inverted = 100 * a + 10 * b + c;
        printf("%u\n", inverted);

    }
    else {
        printf("Invalid Input");
    }
}

void task2() {
    unsigned num1;
    int a, b, c;

    printf("Enter the number: ");
    scanf("%u", &num1);

    if (num1 >= 100 && num1 <= 999) {
        a = num1 % 10;
        b = (num1 / 10) % 10;
        c = num1 / 100;

        if (a != b && a != c && b != c && c != a) {
            printf("%d%d%d\n", a, b, c);
            printf("%d%d%d\n", a, c, b);
            printf("%d%d%d\n", b, a, c);
            printf("%d%d%d\n", b, c, a);
            printf("%d%d%d\n", c, b, a);
            printf("%d%d%d\n", c, a, b);
        }
        else {
            printf("Invalid Input");
        }
    }

}

void task3() {
    int num1, num2, num3, cond1, cond2;
    printf("Enter the numbers: ");
    scanf("%u, %u, %u, ", &num1, &num2, &num3);

    const long long cond = pow(2, 21);

    if (abs(num1) < cond && abs(num2) < cond && abs(num3) < cond) {
        printf("%d", num1 * num2 * num3);
    }
}

uint16_t mul(uint8_t x, uint8_t y) {
    uint16_t z = x * y; // become int?
    return z;
}



void task4() {
    uint8_t x, y;
    uint16_t z;

    printf("x, y: ");
    scanf("%hhu, %hhu", &x, &y);

    z = mul(x, y);
    printf("z = %hu", z);
}

void task5() {
    double num1, num2;
    printf("Enter the number: ");
    scanf("%lf, %lf", &num1, &num2);

    if (num1 > num2) {
        printf("Greater number: %lf\n ", num1);
        printf("Lesser number %lf\n: ", num2);
    }
    else if (num1 < num2) {
        printf("Greater number: %lf\n ", num2);
        printf("Lesser number %lf\n: ", num1);
    }

}

void task6() {
    float num1, num2, num3;
    printf("Enter three real numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    float abs_num1 = fabs(num1);
    float abs_num2 = fabs(num2);
    float abs_num3 = fabs(num3);

    float max_abs = abs_num1;
    if (abs_num2 > max_abs) {
        max_abs = abs_num2;
    }
    else if (abs_num3 > max_abs) {
        max_abs = abs_num3;
    }

    float min_abs = abs_num1;
    if (abs_num2 < min_abs) {
        min_abs = abs_num2;
    }
    else if (abs_num3 < min_abs) {
        min_abs = abs_num3;
    }

    printf("Largest by absolute value: %.2f\n", max_abs);
    printf("Smallest by absolute value: %.2f\n", min_abs);
}


// 7 (b)
void task7() {
    double a, b, c;
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double D = b * b - 4 * a * c;

    if (a != 0) {
        if (D < 0) {
            printf("The equation has no real solutions.\n");
        } else {
            double y1 = (-b + sqrt(D)) / (2 * a);
            double y2 = (-b - sqrt(D)) / (2 * a);

            printf("Solutions for y are: y1 = %.2f, y2 = %.2f\n", y1, y2);

            // Повертаємось до x
            if (y1 >= 0) {
                printf("x1 = %.2f, x2 = %.2f\n", sqrt(y1), -sqrt(y1));
            } else {
                printf("No real solutions for y1\n");
            }

            if (y2 >= 0) {
                printf("x3 = %.2f, x4 = %.2f\n", sqrt(y2), -sqrt(y2));
            } else {
                printf("No real solutions for y2\n");
            }
        }
    }
    else {
      printf("a = 0, so the equation reduces to the linear, and root is = %.2f\n", -1 * c * b);
    }

}

int main() {
    task7();
}
