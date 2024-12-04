#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double radius;
    double x, y;
public:
    Circle(double radius, double x = 0, double y = 0)
        : radius(radius), x(x), y(y) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }

    void rotate(double angle) override {
        // cirlce angle will not change
    }

    void show() override {
        std::cout << "Circle with radius " << radius
                  << ", Area: " << area() << std::endl;
    }
};

#endif
