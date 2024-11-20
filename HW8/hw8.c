#include <stdio.h>

void task22() {
    int n;
    printf("Enter n (the matrix will be of size (2n + 1) x (2n + 1)): ");
    scanf("%d", &n);

    int size = 2 * n + 1;
    int matrix[size][size];

    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][size - j - 1];
            matrix[i][size - j - 1] = temp;
        }
    }

    printf("The mirrored matrix is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}



int main() {
    task22();
}
