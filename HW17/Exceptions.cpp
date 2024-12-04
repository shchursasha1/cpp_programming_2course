#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input: Value is outside the range of a 3-byte integer.";
    }
};

class OverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Overflow error: Operation results in a value outside the valid range.";
    }
};

class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero error.";
    }
};
