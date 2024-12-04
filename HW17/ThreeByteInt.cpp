#include "Exceptions.cpp"

class ThreeByteInt {
private:
    static const int MIN_VALUE = -(1 << 23); // -2^23
    static const int MAX_VALUE = (1 << 23) - 1; // 2^23 - 1
    int value;

    void validateRange(int v) const {
        if (v < MIN_VALUE || v > MAX_VALUE) {
            throw OverflowException();
        }
    }

public:
    ThreeByteInt(int v = 0) {
        if (v < MIN_VALUE || v > MAX_VALUE) {
            throw InvalidInputException();
        }
        value = v;
    }

    ThreeByteInt(const ThreeByteInt& other) : value(other.value) {}

    ThreeByteInt operator+(const ThreeByteInt& other) const {
        int result = value + other.value;
        validateRange(result);
        return ThreeByteInt(result);
    }

    ThreeByteInt operator-(const ThreeByteInt& other) const {
        int result = value - other.value;
        validateRange(result);
        return ThreeByteInt(result);
    }

    ThreeByteInt operator*(const ThreeByteInt& other) const {
        long long result = static_cast<long long>(value) * other.value;
        if (result < MIN_VALUE || result > MAX_VALUE) {
            throw OverflowException();
        }
        return ThreeByteInt(static_cast<int>(result));
    }

    ThreeByteInt operator/(const ThreeByteInt& other) const {
        if (other.value == 0) {
            throw DivisionByZeroException();
        }
        return ThreeByteInt(value / other.value);
    }

    ThreeByteInt& operator=(const ThreeByteInt& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    int getValue() const {
        return value;
    }

    void print() const {
        std::cout << value << std::endl;
    }
};
