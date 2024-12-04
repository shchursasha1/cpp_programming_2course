#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

class Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual bool is_intersect();
    virtual void show() = 0;


    virtual ~Figure() = default;
};

#endif
