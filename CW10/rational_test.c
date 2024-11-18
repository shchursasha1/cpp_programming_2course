#include "ratio.h"

int main() {
    Rational a, b, c;

    input(&a);
    input(&b);

    c = add(a, b);
    reduce(&c);
    output(c);

    printf("a is greater that b?: %d ", greater(a, b));
}