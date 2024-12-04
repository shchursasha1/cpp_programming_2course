#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Array {
private:
    std::vector<T> data;
    size_t size;

public:
    // Constructor
    Array(const std::vector<T>& input) : data(input), size(input.size()) {}

    void display() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    size_t getSize() const {
        return size;
    }

    void hashSort() {
        if (data.empty()) {
            return;
        }

        if constexpr (!std::is_integral<T>::value) {
            throw std::invalid_argument("Hash sort is only applicable to integral types.");
        }

        T minValue = *std::min_element(data.begin(), data.end());
        T maxValue = *std::max_element(data.begin(), data.end());

        std::vector<int> hashTable(maxValue - minValue + 1, 0);

        for (const auto& elem : data) {
            hashTable[elem - minValue]++;
        }

        data.clear();
        for (size_t i = 0; i < hashTable.size(); ++i) {
            while (hashTable[i]-- > 0) {
                data.push_back(static_cast<T>(i + minValue));
            }
        }
    }
};

#endif // ARRAY_H
