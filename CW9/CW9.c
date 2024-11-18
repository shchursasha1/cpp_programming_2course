# include <stdio.h>
# include <math.h>
#include <stdlib.h>

double* input_vec(int n){
    double* vec = calloc(n, sizeof(*vec));
    for (int i = 0 ; i < n; i++){
        printf("a[%d]=",i);
        scanf("%lf",&vec[i]);
    }
    return vec;
}

void delete_vec(double *arr) {
    if (arr) {
        free(arr);
    }
}

double* sub_vec(const double* vec1,const double* vec2, int n){

    double* vec3 = calloc(n,sizeof(*vec3));

    for (int i = 0; i < n ;i++) {
        vec3[i] = vec1[i]- vec2[i];
    }
    return vec3;
}

void output_vec(const double *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void input_sqrt_arr(int n) {
    double arr[];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
}

double sum_sqrt(const double *arr, int n) {
    double sum = 0;
    double *begin = arr;
    double *end = arr + n;
    for (begin <= end; begin++;) {
        double n_arr = *begin;
        sum += pow(n_arr, 2);
    }
    return sum;
}

struct Stack {
    int data;
    struct Stack* addr;
} Stack;

double** input_matrix(int n) {
    double** matrix = calloc(n, sizeof(double*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (double*) calloc(n, sizeof(double));
        for (int j = 0; j < n; j++) {
            printf("a[%d, %d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}

void output_matrix(const double **matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void delete_matrix(double **matrix, int n) {

    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }

        free(matrix);
    }

}

double** mult_matrix(const double **matrix1, const double **matrix2, int n) {
    double** matrix3 = calloc(n, sizeof(double*));

    for (int i = 0; i < n; i++) {
        matrix3[i] = (double*) calloc(n, sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix3;
}


void task1() {
    unsigned n;
    printf("n = ");
    scanf("%u", &n);
    double *arr;
    arr = (double *)malloc(n * sizeof(*arr));
    input_sqrt_arr(n);
    double res = sum_sqrt(arr, n);
    printf("res = %lf\n", res);
    free(arr);
}

void task2() {
    struct Stack s;
    int x, i = 0, a[ ];

    do {
        struct Stack t;
        scanf("%d", &x);
        // a[i++] = x;
        // int *mem;
        // mem = malloc(sizeof(x));
        // *mem = x;
        t.data = x;
        t.addr = malloc(sizeof(Stack));
        t.addr = Stack.addr;
        s.addr = NULL;
        s.data = 0;
    } while(x != 0);

    struct Stack t1;
    while(s.addr != NULL) {
        x = s.data;
        s = *(s.addr);
    }
}

void task3() {
    size_t n;
    double *vec1, *vec2, *vec3;

    printf("Enter n: \n");
    scanf("%zu", &n);

    vec1 = input_vec(n);
    output_vec(vec1, n);

    vec2 = input_vec(n);
    output_vec(vec2, n);

    vec3 = sub_vec(vec1, vec2, n);
    output_vec(vec3, n);

    delete_vec(vec1);
    delete_vec(vec2);
    delete_vec(vec3);
}

void task4() {
    size_t n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%zu", &n);

    double** matr1 = input_matrix(n);
    double** matr2 = input_matrix(n);

    double** matr3 = mult_matrix(matr1, matr2, n);

    printf("Result of multiplication:\n");
    output_matrix(matr3, n);

    delete_matrix(matr1, n);
    delete_matrix(matr2, n);
    delete_matrix(matr3, n);
}

