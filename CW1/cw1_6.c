// Celsius to Fahrenheit

#include <stdio.h>
#include <math.h>

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("F = %.2f\n", fahrenheit);

}
