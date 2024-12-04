#include "Figure.h"

class Trapezoid : public Figure {
private:
    double a, b, h; // Base lengths and height
    std::vector<std::pair<double, double>> vertices; // Vertices

public:
    Trapezoid(double base1, double base2, double height)
        : a(base1), b(base2), h(height) {
        vertices = {{0, 0}, {a, 0}, {b, h}, {0, h}};
    }

    double area() const override {
        return 0.5 * (a + b) * h;
    }

    double perimeter() const override {
        double side1 = sqrt(pow((b - a), 2) + pow(h, 2));
        double side2 = h;
        return a + b + side1 + side2;
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
        std::cout << "Trapezoid with area " << area()
                  << " and perimeter " << perimeter() << std::endl;
        std::cout << "Vertices: ";
        for (const auto& vertex : vertices) {
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        std::cout << std::endl;
    }
};
