#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int minAge;
    int maxAge;
} Toy;

int findMaxInGroup(int* array, int start, int count) {
    int max = array[start];
    for (int i = start + 1; i < start + count; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int task8() {
    int n;
    FILE *fileF, *fileG;

    fileF = fopen("F.txt", "r");

    if (fileF == NULL) {
        printf("Error: Unable to open file F.txt\n");
        return 1;
    }

    int sizeF = 0;
    int* F = NULL;
    int temp;

    while (fscanf(fileF, "%d", &temp) == 1) {
        sizeF++;
        F = (int*)realloc(F, sizeF * sizeof(int));

        if (F == NULL) {
            printf("Memory allocation failed.\n");
            fclose(fileF);
            return 1;

        }
        F[sizeF - 1] = temp;
    }
    fclose(fileF);

    if (sizeF == 0) {
        printf("Error: File F.txt is empty.\n");
        return 1;
    }

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid value for n. It must be positive.\n");
        free(F);
        return 1;
    }

    int* G = (int*)malloc(((sizeF + n - 1) / n) * sizeof(int));
    if (G == NULL) {
        printf("Memory allocation failed.\n");
        free(F);
        return 1;
    }

    int groupCount = 0;
    for (int i = 0; i < sizeF; i += n) {
        int elementsInGroup = (i + n <= sizeF) ? n : sizeF - i;
        G[groupCount++] = findMaxInGroup(F, i, elementsInGroup);
    }

    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        printf("Error: Unable to open file G.txt for writing.\n");
        free(F);
        free(G);
        return 1;
    }

    for (int i = 0; i < groupCount; i++) {
        fprintf(fileG, "%d\n", G[i]);
    }
    fclose(fileG);

    printf("File G.txt has been created successfully.\n");

    free(F);
    free(G);
    return 0;
}

// for task 12
void displayToys(Toy* toys, int count) {
    printf("List of Toys:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Price: %.2f UAH, Age Range: %d-%d years\n",
               toys[i].name, toys[i].price, toys[i].minAge, toys[i].maxAge);
    }
}

int readToysFromFile(const char* filename, Toy* toys, int maxCount) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return 0;
    }

    int count = fread(toys, sizeof(Toy), maxCount, file);
    fclose(file);
    return count;
}

void writeToysToFile(const char* filename, Toy* toys, int count) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }
    fwrite(toys, sizeof(Toy), count, file);
    fclose(file);
}

// task12 (д)
void findToysByName(Toy* toys, int count, const char* name) {
    float totalPrice = 0;
    int found = 0;

    printf("Toys with name \"%s\":\n", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(toys[i].name, name) == 0) {
            printf("Price: %.2f UAH, Age Range: %d-%d years\n",
                   toys[i].price, toys[i].minAge, toys[i].maxAge);
            totalPrice += toys[i].price;
            found = 1;
        }
    }

    if (found) {
        printf("Total price of toys with name \"%s\": %.2f UAH\n", name, totalPrice);
    } else {
        printf("No toys found with name \"%s\".\n", name);
    }
}

// task12 (д)
int task12() {
    const int MAX_TOYS = 100;
    Toy toys[MAX_TOYS];

    int toyCount = readToysFromFile("toys.bin", toys, MAX_TOYS);
    if (toyCount == 0) {
        printf("No toys read from the file.\n");
        return 1;
    }

    displayToys(toys, toyCount);

    char name[50];
    printf("\nEnter the name of the toy to search: ");
    scanf("%49s", name);
    findToysByName(toys, toyCount, name);

    return 0;
}


int main() {
    task12();
}
