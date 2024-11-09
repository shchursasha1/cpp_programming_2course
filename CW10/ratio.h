// Header file for Rational
#pragma once
#include <stdio.h>
#include <stdbool.h>

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

typedef struct Rational {
    int numerator;
    unsigned int denominator;
} Rational;

extern Rational add(Rational x, Rational y);
extern Rational mult(Rational x, Rational y);
extern bool greater (Rational x, Rational y);
extern void reduce(Rational *x);
extern void output(Rational x);
extern int input(Rational *x);

#endif //__RATIONAL_H__

