#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Figure.h"

class Parallelogram : public Figure {
private:
    double base, side, height;
    std::vector<std::pair<double, double>> vertices;

public:
    Parallelogram(double base, double side, double height)
        : base(base), side(side), height(height) {
        vertices = {{0, 0}, {base, 0}, {base + side, height}, {side, height}};
    }

    double area() const override {
        return base * height;
    }

    double perimeter() const override {
        return 2 * (base + side);
    }

    void rotate(double angle) override {
        double radians = angle * M_PI / 180.0;
        for (auto& vertex : vertices) {
            double x = vertex.first;
            double y = vertex.second;
            vertex.first = x * cos(radians) - y * sin(radians);
            vertex.second = x * sin(radians) + y * cos(radians);
        }
    }

    void move(double dx, double dy) override {
        for (auto& vertex : vertices) {
            vertex.first += dx;
            vertex.second += dy;
        }
    }

    void show() override {
        std::cout << "Parallelogram with area " << area()
                  << " and perimeter " << perimeter() << std::endl;
        std::cout << "Vertices: ";
        for (const auto& vertex : vertices) {
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        std::cout << std::endl;
    }
};

#endif
