#include <stdio.h>

typedef struct {
    int x, y;
    float mass;
} Point;


int readPointsFromFile(const char* filename, Point* points, int maxPoints) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s.\n", filename);
        return 0;
    }

    int count = 0;
    while (count < maxPoints && fscanf(file, "[%d,%d,%f],", &points[count].x, &points[count].y, &points[count].mass) == 3) {
        count++;
           }

    fclose(file);
    return count;
}

float calculateMoment(Point p) {
    return p.mass * (p.x + p.y);
}

void findMaxMoments(Point* points, int count) {
    if (count < 2) {
        printf("Error: At least two points are required.\n");
        return;
    }

    int max1 = 0, max2 = 1;
    if (calculateMoment(points[max2]) > calculateMoment(points[max1])) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < count; i++) {
        float currentMoment = calculateMoment(points[i]);
        if (currentMoment > calculateMoment(points[max1])) {
            max2 = max1;
            max1 = i;
        } else if (currentMoment > calculateMoment(points[max2])) {
            max2 = i;
        }
    }

    printf("Point 1: [%d, %d, %.2f] with moment %.2f\n", points[max1].x, points[max1].y, points[max1].mass, calculateMoment(points[max1]));
    printf("Point 2: [%d, %d, %.2f] with moment %.2f\n", points[max2].x, points[max2].y, points[max2].mass, calculateMoment(points[max2]));
}

int task20() {
    const int MAX_POINTS = 100;
    Point points[MAX_POINTS];

    int count = readPointsFromFile("points.txt", points, MAX_POINTS);
    if (count == 0) {
        printf("No points read from the file.\n");
        return 1;
    }

    findMaxMoments(points, count);
    return 0;
}


int main() {
    task20();
}
