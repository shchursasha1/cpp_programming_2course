#include <iostream>
#include <cmath>

using namespace std;


class Point2D {
protected:
    double x, y;
    int dimension;

public:

    Point2D() : x(0), y(0), dimension(2) {}


    Point2D(double x, double y) : x(x), y(y), dimension(2) {}


    void input() {
        cout << "Enter coordinates x and y: ";
        cin >> x >> y;
    }

    void show() const {
        cout << "(" << x << ", " << y << ")";
    }

    double getX() const { return x; }

    double getY() const { return y; }

    double distance(const Point2D& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }


    int getDimension() const {
        return dimension;
    }
};


class Point3D : public Point2D {
private:
    double z;

public:
    Point3D(double x = 0, double y = 0, double z = 0) : Point2D(x, y), z(z) {
        dimension = 3;
    }

    void input() {
        cout << "Enter coordinates x, y, and z: ";
        cin >> x >> y >> z;
    }

    void show() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    double getZ() const { return z; }

    double distance(const Point3D& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }
};


class Segment {
private:
    Point2D p1, p2;
    Point3D p1_3D, p2_3D;
    bool is3D;

public:
    Segment(Point2D a, Point2D b) : p1(a), p2(b), is3D(false) {}

    Segment(Point3D a, Point3D b) : p1_3D(a), p2_3D(b), is3D(true) {}


    double length() const {
        if (is3D) {
            return p1_3D.distance(p2_3D);
        } else {
            return p1.distance(p2);
        }
    }

    static bool checkIntersection(Segment& a, Segment& b) {
        if (a.is3D || b.is3D) {
            cout << "Intersection check is not implemented for 3D segments." << endl;
            return false;
        }

        double x1 = a.p1.getX(), y1 = a.p1.getY();
        double x2 = a.p2.getX(), y2 = a.p2.getY();
        double x3 = b.p1.getX(), y3 = b.p1.getY();
        double x4 = b.p2.getX(), y4 = b.p2.getY();

        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (denominator == 0) {
            return false; // Segments are parallel
        }

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / denominator;

        return (t >= 0 && t <= 1 && u >= 0 && u <= 1);
    }


    void show() const {
        if (is3D) {
            cout << "3D Segment from ";
            p1_3D.show();
            cout << " to ";
            p2_3D.show();
        } else {
            cout << "2D Segment from ";
            p1.show();
            cout << " to ";
            p2.show();
        }
    }
};

int main() {
    Point2D p1(1, 2), p2(4, 6);
    Segment s1(p1, p2);
    cout << "Length of 2D: " << s1.length() << endl;

    Point3D p3D1(1, 2, 3), p3D2(4, 5, 6);
    Segment s2(p3D1, p3D2);
    cout << "Length of 3D: " << s2.length() << endl;

    Segment s3(Point2D(1, 1), Point2D(5, 5));
    Segment s4(Point2D(1, 5), Point2D(5, 1));
    cout << "Intersection: " << Segment::checkIntersection(s3, s4);
}
