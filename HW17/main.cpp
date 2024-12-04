#include "ThreeByteInt.cpp"

int main() {
    try {
        ThreeByteInt a(5000000); // Invalid input, should throw
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ThreeByteInt a(1000000);
        ThreeByteInt b(8000000); // Valid input
        ThreeByteInt c = a + b; // Should throw overflow exception
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ThreeByteInt a(10);
        ThreeByteInt b(0);
        ThreeByteInt c = a / b; // Division by zero
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ThreeByteInt a(1000);
        ThreeByteInt b(2000);
        ThreeByteInt c = a + b; // Valid operation
        c.print();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
