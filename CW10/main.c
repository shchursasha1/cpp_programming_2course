#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Date {
    int day;
    int month;
    int year;
}Date;

struct Cell {
    unsigned char horizontal;
    char vertical;
};

typedef struct Vertex {
    long double x;
    long double y;
}Vertex;

typedef struct Rectangle {
    Vertex v1;
    Vertex v2;
}Rectangle;

typedef struct Poly {
    unsigned n;
    double* a;
}Poly;

void output_date(Date d) {
    printf("%d %d %d", d.day, d.month, d.year);
}

void output_cell(struct Cell c) {
    printf("%c%hhu\n", c.vertical, c.horizontal);
}

void output_vertex(struct Vertex v) {
    printf("(%lg, %lg)", v.x, v.y);
}

void output_rectangle(const Rectangle* r) {
    output_vertex(r->v1);
    printf("\t\n");
    output_vertex(r->v2);
}

void output_poly(Poly p) {
    for(int i = 0; i < p.n; i++) {
        printf("%lf*x^%d + ", p.a[i], i);
    }
    printf("%lf*x^%d", p.a[p.n], p.n);
}

Vertex input_vertex() {
    Vertex v;
    printf("x, y = \n");
    scanf("%lg %lg", &v.x, &v.y);
    return v;
}


int input_poly(Poly* p) {
    printf("Enter n: \n");
    scanf("%d", &p->n);
    p->a = (double*) calloc(p->n + 1, sizeof(*(p->a)));
    for(int i = 0; i < (p->n + 1); i++) {
        printf("a[%d] = \n", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void delete_poly(Poly* p) {
    if (p->a) {
        free(p->a);
    }
}

int input_rectangle(Rectangle* r) {
    r->v1 = input_vertex();
    r->v2 = input_vertex();
    return 0;
}

int input_cell(struct Cell* c) {
    printf("Enter vertical: \n");

    scanf("%c", &c->vertical);
    printf("Enter horizontal: \n");
    scanf("%ssh", &c->horizontal);

    if (c->vertical >= 'a'&&
        c->vertical <= 'h'||
        c->vertical >= 'A'&&
        c->vertical <= 'H'&&
        c->horizontal >= 1&&
        c->horizontal<= 8) {
        return 1;
    }
    return 0;
}

int input_date(Date* d) {
    printf("Input date: \n");
    int n = scanf("%d %d %d", &d -> day, &d -> month, &d -> year);
    return n;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int is_valid_date(Date date) {

    if (date.year < 0) return 0;


    if (date.month < 1 || date.month > 12) return 0;


    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (is_leap_year(date.year)) {
        days_in_month[2] = 29;
    }


    if (date.day < 1 || date.day > days_in_month[date.month]) return 0;

    return 1;
}

void next_day(Date* date) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (is_leap_year(date->year)) {
        days_in_month[2] = 29;
    }


    date->day++;
    if (date->day > days_in_month[date->month]) {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

const char* day_of_week(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100; //
    int j = year / 100; //
    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    f = f % 7;

    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[f];
}


void task1() {
    Poly p;
    input_poly(&p);
    output_poly(p);
    delete_poly(&p);
}

int task2_hit_queen(struct Cell f1, struct Cell f2) {
    if((f1.horizontal == f2.horizontal)||
        (f1.vertical == f2.vertical)||
        (fabs(f1.vertical - f2.vertical) == fabs(f2.horizontal - f2.vertical))) {
        return 1;
        }
    return 0;
}

int task3() {
    Date date;

    printf("Enter day: ");
    scanf("%d", &date.day);
    printf("Enter month: ");
    scanf("%d", &date.month);
    printf("Enter year: ");
    scanf("%d", &date.year);

    if (!is_valid_date(date)) {
        printf("Invalid date entered.\n");
        return 1;
    }

    next_day(&date);
    printf("Tomorrow's date: %02d/%02d/%d\n", date.day, date.month, date.year);

    const char* weekday = day_of_week(date.day, date.month, date.year);
    printf("Day of the week: %s\n", weekday);

    return 0;
}

int main() {
    task3();
}