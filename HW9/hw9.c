#include <stdio.h>
#include <stdlib.h>

// task 9.9 (в)
int task9() {
    int n, m;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    double** array = (double**)malloc(n * sizeof(double*));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = (double*)malloc(m * sizeof(double));

        if (array[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i);

            for (int j = 0; j < i; j++) {
                free(array[j]);
            }

            free(array);
            return 1;
        }
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", array[i][j]);
        }
        printf("\n");
    }

    n++; // Збільшуємо кількість рядків
    array = (double**)realloc(array, n * sizeof(double*));

    if (array == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    array[n - 1] = (double*)malloc(m * sizeof(double));
    if (array[n - 1] == NULL) {
        printf("Memory allocation failed for the new row.\n");

        for (int i = 0; i < n - 1; i++) {
            free(array[i]);
        }

        free(array);
        return 1;
    }

    printf("Enter the elements of the new row:\n");
    for (int j = 0; j < m; j++) {
        printf("Element [%d][%d]: ", n - 1, j);
        scanf("%lf", &array[n - 1][j]);
    }

    printf("\nThe updated matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }

    free(array);

    return 0;
}

int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** input_matrix(int* rows, int* cols) {
    printf("Enter amount of rows and cols: ");
    scanf("%d %d", rows, cols);

    int** matrix = allocate_matrix(*rows, *cols);
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** multiply_matrices(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB, int* rowsC, int* colsC) {
    if (colsA != rowsB) {
        printf("Multiplication is impossible due to dimensional mismatch!\n");
        return NULL;
    }

    *rowsC = rowsA;
    *colsC = colsB;
    int** C = allocate_matrix(*rowsC, *colsC);

    for (int i = 0; i < *rowsC; i++) {
        for (int j = 0; j < *colsC; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int task10() {
    int n;
    printf("Enter amount of matrices: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least 2 matrices to multiply.\n");
        return 0;
    }

    int*** matrices = (int***)malloc(n * sizeof(int**));
    int* rows = (int*)malloc(n * sizeof(int));
    int* cols = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Matrix %d:\n", i + 1);
        matrices[i] = input_matrix(&rows[i], &cols[i]);
    }

    int** result = matrices[0];
    int resultRows = rows[0], resultCols = cols[0];

    for (int i = 1; i < n; i++) {
        int resultRowsNew, resultColsNew;
        int** temp = multiply_matrices(result, resultRows, resultCols, matrices[i], rows[i], cols[i], &resultRowsNew, &resultColsNew);

        if (temp == NULL) {
            for (int j = 0; j <= i; j++) {
                free_matrix(matrices[j], rows[j]);
            }
            free(matrices);
            free(rows);
            free(cols);
            return 1;
        }

        if (i > 1) free_matrix(result, resultRows);
        result = temp;
        resultRows = resultRowsNew;
        resultCols = resultColsNew;
    }

    printf("Result matrix:\n");
    print_matrix(result, resultRows, resultCols);

    free_matrix(result, resultRows);
    for (int i = 1; i < n; i++) {
        free_matrix(matrices[i], rows[i]);
    }
    free(matrices);
    free(rows);
    free(cols);

    return 0;
}

int main() {
    task9();
}
