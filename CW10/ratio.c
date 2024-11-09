#include <stdio.h>
#include "ratio.h"

void output(Rational x) {
    printf("%d/%d\n", x.numerator, x.denominator);
}

int input(Rational *x) {
    printf("Enter numerator: ");
    scanf("%d", &x -> numerator);
    printf("Enter denominator: ");
    scanf("%d", &x -> denominator);

    return x -> numerator != 0;
}

Rational add(Rational x, Rational y) {
    Rational z;
    z.numerator = (int)(x.numerator * y.denominator + x.denominator * y.numerator);
    z.denominator = x.denominator * y.denominator;
    return z;
}

Rational mult(Rational x, Rational y) {
    Rational z;

    z.numerator = (int)(x.numerator * y.numerator);
    z.denominator = (int)(x.denominator * y.denominator);

    return z;
}

unsigned gcd (unsigned n, unsigned m) {
    if (m == 0) {
        return n;
    }
    return gcd(m, n % m);
}

bool greater(Rational x, Rational y) {
    int left = x.numerator * y.denominator;
    int right = y.numerator * x.denominator;

    if (left > right) {
        return 1; // x > y
    } else if (left < right) {
        return -1; // x < y
    } else {
        return 0; // x == y
    }
}

void reduce(Rational *x) {
    unsigned g;
    int n = x -> numerator;
    unsigned m = x -> denominator;

    if (n > 0) {
        if (n > m) {
            g = gcd(n, m);
        } else {
            g = gcd(m, n);
        }
    }

    x -> numerator /= g;
    x -> denominator /= g;
}
