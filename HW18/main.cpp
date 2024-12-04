#include <iostream>
#include "Array.cpp"

int main() {
    try {
        Array<int> arr({5, 3, 8, 6, 2, 7, 4, 1, 9, 10});

        std::cout << "Original Array: ";
        arr.display();
        std::cout << "Size of Array: " << arr.getSize() << std::endl;

        arr.hashSort();

        std::cout << "Sorted Array: ";
        arr.display();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
