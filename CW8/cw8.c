#include <math.h>
#include <stdio.h>
typedef int MTYPE;
#define M 3
#define N 3
#define MAX_SIZE 25

void output_matrix(MTYPE a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t ", a[i][j]);
            printf("\n");
        }
    }
}


void task1() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    unsigned n, m;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == m) {
                a[i][j] = m;
            }
        }
    }

    output_matrix(a);
}

void task2() {
    double array[3][3] = {{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double a;
    unsigned i, j;

    printf("Enter i: ");
    scanf("%d", &i);
    printf("Enter j: ");
    scanf("%d", &j);
    printf("Enter a: ");
    scanf("lf", &a);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            array[i][j] = a;
        }
    }

    output_matrix(array);
}

void task3() {
    unsigned m, n;

    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);

    double matrix[m][n];
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task4() {
    unsigned m, n;

    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);

    double matrix[m][n];
    for (int i = 0; i < m; i++) {
        printf("matrix[%d]: \n", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task5() {
    int array[10][10], transpose[10][10], rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("\nEntered matrix: \n");
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            printf("%d  ", array[i][j]);
            if (j == cols - 1)
                printf("\n");
        }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = array[i][j];
        }

    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < cols; ++i)
        for (int j = 0; j < rows; ++j) {
            printf("%d  ", transpose[i][j]);
            if (j == rows - 1)
                printf("\n");
        }
}

void task6() {
    unsigned m, n;
    int k;
    double sum = 0.0;

    printf("Enter number (i - j) = k: \n");
    scanf("%d", &k);

    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);

    double matrix[m][n];
    for (int i = 0; i < m; i++) {
        printf("matrix[%d]: \n", i);

        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == k) {
                sum += matrix[i][j];
            }
        }
    }
    printf("The sum is: %.2lf\n", sum);
}

double determinant(double matrix[10][10], int n) {
    double det = 1.0;

    for (int k = 0; k < n; k++) {
        int max_row = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(matrix[i][k]) > fabs(matrix[max_row][k])) {
                max_row = i;
            }
        }

        // swap rows
        if (k != max_row) {
            for (int j = 0; j < n; j++) {
                double temp = matrix[k][j];
                matrix[k][j] = matrix[max_row][j];
                matrix[max_row][j] = temp;
            }
            det = -det;
        }

        // Якщо елемент на діагоналі є нульовим, визначник дорівнює нулю
        if (fabs(matrix[k][k]) < 1e-10) {
            return 0;
        }

        det *= matrix[k][k];
        for (int i = k + 1; i < n; i++) {
            double factor = matrix[i][k] / matrix[k][k];

            for (int j = k; j < n; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }

    return det;
}

void task7() {
    double array[3][3];

    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    double det = determinant(array, 3);
    printf("The determinant is: %.2lf\n", det);
}

int main() {
    task4();
}
