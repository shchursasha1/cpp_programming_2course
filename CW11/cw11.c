#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int id;
    double x1, y1;
    double x2, y2;
} Rectangle;

int read_file(const char *file_name, double *arr) {
    FILE * fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }
    double item;
    int k = 0;
    while(!feof(fp)) {
        int res = fread(&item, sizeof(item), 1, fp);
        if(res != 1) {
            break;
        }
        arr[k++] = item;
    }
    fclose(fp);
    return k;
}

int write_file(const char *file_name, double *arr, int n) {
    FILE * fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }
    int res = fwrite(arr, sizeof(*arr), n, fp);
    fclose(fp);
    return res;
}

void task1() {
    char file_name[50] = "test.txt";
    int n;

    printf("Enter n: \n");
    scanf("%d", &n);

    double* arr1 = (double*)malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d]: \n", i);
        scanf("%lf", &arr1[i]);
    }

    write_file(file_name, arr1, n);
    free(arr1);

    double* arr2 = (double*)malloc(sizeof(double) * n);
    int k = read_file(file_name, arr2);

    for (int i = 0; i < k; i++) {
        printf("%.0lf, ", arr2[i]);
    }

    free(arr2);
}

int task2() {
    const char* fname = "file_1";
    FILE * f = fopen(fname, "wb");

    if (f == NULL) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    int n;

    printf("n = \n");
    scanf("%d", &n);

    double x;
    for (int i = 0; i < n; i++) {
        printf("x = \n");
        scanf("%lf", &x);
        fwrite(&x, sizeof(x), 1, f);
    }
    fclose(f);

    double a;

    printf("a = \n");
    scanf("%lf", &a);

    f = fopen(fname, "rb");
    double mas[10];
    const char * fname2 = "file2";
    FILE * g = fopen(fname2, "wb");
    int i = 0;
    int k = 0;

    while(1) {
        if(feof(f)) {
            break;
        }
        fread(&x, sizeof(double), 1, f);
        if (fabs(x) < a) {
            fwrite(&x, sizeof(double), 1, g);
        }
        else {
            mas[k++] = x;
        }
        i++;
    }
    fclose(f);
    fclose(g);

    g = fopen(fname2, "rb");
    i = 0;
    while(1) {
        if(feof(g)) {break;}
        fread(&x, sizeof(double), 1, g);
        printf("x%d = %lf\n", i++, x);
    }
    fclose(g);

    f = fopen(fname, "wb");
    fwrite(mas, sizeof(double), k, f);
    f = freopen(fname, "rb", f);
    i = 0;

    while(1) {
        if(feof(f)) {break;}
        fread(&x, sizeof(double), 1, f);
        printf("x%d = %lf\n", i++, x);
    }

    fclose(f);
    return 0;
}

bool is_power_of_3(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

void task3() {
    FILE *fileF, *fileG;
    int num;

    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        printf("Error opening file F.\n");
        return 1;
    }

    printf("Enter integers (0 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        fprintf(fileF, "%d\n", num);
    }
    fclose(fileF);

    fileF = fopen("F.txt", "r");
    fileG = fopen("G.txt", "w");
    if (fileF == NULL || fileG == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(fileF, "%d", &num) != EOF) {
        if (is_power_of_3(num)) {
            fprintf(fileG, "%d\n", num);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("File G with numbers that are powers of 3 has been created.\n");
}

double rectangle_area(Rectangle rect) {
    return fabs((rect.x2 - rect.x1) * (rect.y2 - rect.y1));
}


void write_rectangles_to_file(char *file_name, int n) {
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        Rectangle rect;
        printf("Enter rectangle %d ID: ", i + 1);
        scanf("%d", &rect.id);
        printf("Enter coordinates (x1, y1) of the top-left corner: ");
        scanf("%lf %lf", &rect.x1, &rect.y1);
        printf("Enter coordinates (x2, y2) of the bottom-right corner: ");
        scanf("%lf %lf", &rect.x2, &rect.y2);

        fwrite(&rect, sizeof(Rectangle), 1, fp);
    }

    fclose(fp);
}


void find_largest_area(char *file_name) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    Rectangle rect;
    Rectangle largest_rect;
    double max_area = -1;

    while (fread(&rect, sizeof(Rectangle), 1, fp)) {
        double area = rectangle_area(rect);
        if (area > max_area) {
            max_area = area;
            largest_rect = rect;
        }
    }

    if (max_area != -1) {
        printf("Rectangle with the largest area:\n");
        printf("ID: %d, Area: %.2lf\n", largest_rect.id, max_area);
        printf("Top-left corner: (%.2lf, %.2lf), Bottom-right corner: (%.2lf, %.2lf)\n",
               largest_rect.x1, largest_rect.y1, largest_rect.x2, largest_rect.y2);
    } else {
        printf("No rectangles in the file.\n");
    }

    fclose(fp);
}


void delete_rectangle_by_id(char *file_name, int id_to_delete) {
    FILE *fp = fopen(file_name, "rb");
    FILE *temp_fp = fopen("temp.bin", "wb");
    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Rectangle rect;
    int found = 0;

    while (fread(&rect, sizeof(Rectangle), 1, fp)) {
        if (rect.id != id_to_delete) {
            fwrite(&rect, sizeof(Rectangle), 1, temp_fp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp_fp);


    remove(file_name);
    rename("temp.bin", file_name);

    if (found) {
        printf("Rectangle with ID %d deleted.\n", id_to_delete);
    } else {
        printf("Rectangle with ID %d not found.\n", id_to_delete);
    }
}


void replace_rectangle_by_index(char *file_name, int index) {
    FILE *fp = fopen(file_name, "rb+");
    if (fp == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }

    fseek(fp, sizeof(Rectangle) * index, SEEK_SET);

    Rectangle new_rect;
    printf("Enter new rectangle ID: ");
    scanf("%d", &new_rect.id);
    printf("Enter new coordinates (x1, y1) of the top-left corner: ");
    scanf("%lf %lf", &new_rect.x1, &new_rect.y1);
    printf("Enter new coordinates (x2, y2) of the bottom-right corner: ");
    scanf("%lf %lf", &new_rect.x2, &new_rect.y2);

    fwrite(&new_rect, sizeof(Rectangle), 1, fp);

    fclose(fp);
}

void task4() {
    char *file_name = "rectangles.bin";

    int n;
    printf("Enter number of rectangles: ");
    scanf("%d", &n);


    write_rectangles_to_file(file_name, n);


    find_largest_area(file_name);

    int id_to_delete;
    printf("Enter rectangle ID to delete: ");
    scanf("%d", &id_to_delete);
    delete_rectangle_by_id(file_name, id_to_delete);

    int index_to_replace;
    printf("Enter the index of the rectangle to replace (0-based): ");
    scanf("%d", &index_to_replace);
    replace_rectangle_by_index(file_name, index_to_replace);

}

int main() {
    task1();
}