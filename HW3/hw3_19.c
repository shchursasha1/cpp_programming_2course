#include <stdio.h>

int task19_d() {
    int number;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    int first_digit = number % 10;
    int second_digit = (number / 10) % 10;

    int condition = first_digit + second_digit;

    if (condition >= 10 && condition <= 100) {
        return 1;
    }

    return 0;
}

int task19_e() {
    double x, y;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);

    double condition = x - y;

    if (condition >= 7) {
        return 1;
    }

    return 0;
}

// 3.19 (є)
int task19_e2() {
    double x, y, z;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    printf("Enter z: ");
    scanf("%lf", &z);

    if (x > 99 || y > 99 || z > 99) {
        return 1;
    }

    return 0;
}


int task19_j() {
    double x, y, z;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    printf("Enter z: ");
    scanf("%lf", &z);

    if ((x < 1001 && y >= 1001 && z >= 1001) ||
        (y < 1001 && x >= 1001 && z >= 1001) ||
        (z < 1001 && x >= 1001 && y >= 1001)) {

        return 1;
    }

    return 0;
}

int main() {
    task19_j();
}
