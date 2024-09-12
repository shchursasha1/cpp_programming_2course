#include <stdio.h>
#include <math.h>

int main() {
    float a;
    float b;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);

    if (a > 0 && b > 0) {
        float c = sqrt(a * a + b * b);
        printf("%f\n", c);
    }

    else {
        printf("a and b cannot be lower than 0");
    }
}
