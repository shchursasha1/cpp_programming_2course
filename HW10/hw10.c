#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

typedef struct Circle {
    double radius;
    double x, y;
} Circle;

typedef struct {
    int nameIndex;
    int gender; // 0 - women, 1 - man
    float height;
} Person;


void inputCircle(Circle* circle) {
    printf("Enter radius: ");
    scanf("%lf", &circle->radius);

    printf("Enter x: ");
    scanf("%lf", &circle->x);
    printf("Enter y: ");
    scanf("%lf", &circle->y);
}

void displayCircle(Circle* circle) {
    printf("Radius: %.2lf\n", circle->radius);
    printf("Center coordinates (x, y): %lf, %lf", circle->x, circle->y);
}

// task 10.6 (є)
void task6() {
    Circle circle;

    inputCircle(&circle);
    displayCircle(&circle);
}

float calculateAverageHeightOfWomen(Person people[], int size) {
    float totalHeight = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (people[i].gender == 0) {
            totalHeight += people[i].height;
            count++;
        }
    }
    return count > 0 ? totalHeight / count : 0; // Уникнення ділення на 0
}

int findTallestMan(Person people[], int size) {
    int tallestIndex = -1;
    float maxHeight = 0;
    for (int i = 0; i < size; i++) {
        if (people[i].gender == 1 && people[i].height > maxHeight) { // Якщо чоловік і найвищий
            maxHeight = people[i].height;
            tallestIndex = i;
        }
    }
    return tallestIndex;
}

void findPeopleWithSameHeight(Person people[], int size, const char* names[]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (people[i].height == people[j].height) {
                printf("People with the same height (%.2f cm): %s and %s\n",
                       people[i].height, names[people[i].nameIndex], names[people[j].nameIndex]);
                return;
            }
        }
    }
    printf("No people with the same height were found.\n");
}

int task14() {
    const char* L[MAX_PEOPLE] = {
        "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank"
    };

    Person P[MAX_PEOPLE] = {
        {0, 0, 165.5},
        {1, 1, 180.2},
        {2, 1, 175.0},
        {3, 0, 165.5},
        {4, 0, 170.0},
        {5, 1, 190.0}
    };

    int size = 6;

    float averageHeightOfWomen = calculateAverageHeightOfWomen(P, size);
    printf("Average height of women: %.2f cm\n", averageHeightOfWomen);

    int tallestManIndex = findTallestMan(P, size);

    if (tallestManIndex != -1) {
        printf("The tallest man is %s with a height of %.2f cm\n",
               L[P[tallestManIndex].nameIndex], P[tallestManIndex].height);
    } else {
        printf("There are no men in the list.\n");
    }

    findPeopleWithSameHeight(P, size, L);

    return 0;
}


int main() {
    task14();
}
