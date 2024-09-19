#include <stdio.h>

int main() {
    float r, m1, m2;
    float gamma = 6.673e-11;

    printf("Enter the radius: ");
    scanf("%f", &r);

    printf("Enter the m1: ");
    scanf("%f", &m1);

    printf("Enter the m2: ");
    scanf("%f", &m2);

    float F = gamma * ((m1 * m2) / (r * r));
    printf("F = %e\n", F);


}