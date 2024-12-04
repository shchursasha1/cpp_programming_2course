#include "Trapezoid.cpp"
#include "Parallelogram.cpp"
#include "Circle.cpp"
#include <vector>
#include <algorithm>

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Trapezoid(4, 6, 5));
    figures.push_back(new Parallelogram(5, 4, 3));
    figures.push_back(new Circle(3, 5, 4));

    figures[0]->move(2, 2);
    figures[1]->move(10, 10);
    figures[2]->move(20, 20);

    figures[0]->show();
    figures[0]->rotate(45);
    figures[0]->show();

    double total_area = 0;
    double total_perimeter = 0;
    for (const auto& figure : figures) {
        total_area += figure->area();
        total_perimeter += figure->perimeter();
    }

    Figure* largestAreaFigure = *std::max_element(figures.begin(), figures.end(),
        [](Figure* a, Figure* b) { return a->area() < b->area(); });

    std::cout << "Total area: " << total_area << std::endl;
    std::cout << "Total perimeter: " << total_perimeter << std::endl;
    std::cout << "Figure with the largest area:" << std::endl;
    largestAreaFigure -> show();

    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}
