#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("Enter a real number x: ");
    scanf("%lf", &x);

    // Calculations without using math.h
    int int_part = (int)x;  // Integer part of the number
    double frac = x - int_part;  // Fractional part of the number
    int ceil_val1 = (x > int_part) ? int_part + 1 : int_part;
    int floor_val1 = (x < int_part) ? int_part - 1 : int_part;
    int round_val1 = (x >= 0) ? (int)(x + 0.5) : (int)(x - 0.5);

    printf("\nWithout using math.h:\n");
    printf("Integer part: %d\n", int_part);
    printf("Fractional part: %.6f\n", frac);
    printf("Smallest integer greater than x: %d\n", ceil_val1);
    printf("Largest integer less than x: %d\n", floor_val1);
    printf("Rounded value: %d\n", round_val1);

    // Calculations using math.h
    int ceil_val2 = ceil(x);
    int floor_val2 = floor(x);
    int round_val2 = round(x);

    printf("\nUsing math.h:\n");
    printf("Integer part: %d\n", (int)floor(x));
    printf("Fractional part: %.5f\n", x - floor(x));
    printf("Smallest integer greater than x: %d\n", ceil_val2);
    printf("Largest integer less than x: %d\n", floor_val2);
    printf("Rounded value: %d\n", round_val2);

    return 0;
}
