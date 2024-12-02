#include <iostream>
#include <fstream>
#include <cmath>

class Rational {
private:
    int numerator;
    unsigned denominator;

public:
    Rational(int n = 0, unsigned d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) {
            std::cout << "Error: Denominator cannot be 0.\n";
            denominator = 1;
        }
        reduce();
    }

    void show() const {
        std::cout << numerator << "/" << denominator << "\n";
    }

    friend std::istream& operator>>(std::istream& in, Rational& r) {
        std::cout << "Input numerator: ";
        in >> r.numerator;
        std::cout << "Input denominator: ";
        in >> r.denominator;

        if (r.denominator == 0) {
            std::cout << "denominator cannot be 0.\n";
            r.denominator = 1;
        }

        r.reduce();
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Rational& r) {
        out << r.numerator << "/" << r.denominator;
        return out;
    }

    Rational operator-(const Rational& other) const {
        int t = numerator * other.denominator - denominator * other.numerator;
        unsigned y = denominator * other.denominator;
        return Rational(t, y);
    }

    Rational operator / (const Rational& other) const {
        if (other.numerator == 0) {
            std::cout << "can't divide by 0\n";
            return Rational(0, 1);
        }
        int t = numerator * other.denominator;
        unsigned y = denominator * other.numerator;
        return Rational(t, y);
    }

private:
    unsigned gcd(unsigned x, unsigned y) {
        while (y != 0) {
            unsigned temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    void reduce() {
        unsigned gcd = gcd(abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

void write_rational_to_file(const Rational& r, const std::string& filename) {
    std::ofstream out(filename);

    if (!out) {
        std::cout << "Failed to open the file\n";
    }

    out << r;
    std::cout << "Rational number was written to file: " << filename << "\n";
}

int main() {
    Rational r1, r2;
    std::cin >> r1;
    std::cin >> r2;
    Rational result = r1 - r2;
    std::cout << "subtraction: " << result << std::endl;
    Rational division_result = r1 / r2;
    std::cout << "division: " << division_result << std::endl;

    write_rational_to_file(result, "output.txt");

    return 0;
}