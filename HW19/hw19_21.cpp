#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <stdexcept>

void saveVectorToFile(const std::vector<std::string>& vec, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Error opening file for writing.");
    }
    for (const auto& elem : vec) {
        size_t size = elem.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outFile.write(elem.data(), size);
    }
    outFile.close();
}

std::vector<std::string> loadVectorFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Error opening file for reading.");
    }
    std::vector<std::string> vec;
    while (inFile.peek() != EOF) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        std::string elem(size, '\0');
        inFile.read(&elem[0], size);
        vec.push_back(elem);
    }
    inFile.close();
    return vec;
}

int main() {
    try {
        std::list<std::string> L;
        std::cout << "Enter elements for list L (type 'end' to stop):" << std::endl;
        std::string input;
        while (true) {
            std::cin >> input;
            if (input == "end") break;
            L.push_back(input);
        }

        std::string filename = "vector.bin";
        std::vector<std::string> V = loadVectorFromFile(filename);

        int index;
        std::cout << "Enter the index of the element in list L to move: ";
        std::cin >> index;

        if (index < 0 || index >= static_cast<int>(L.size())) {
            throw std::out_of_range("Index out of range.");
        }

        auto it = L.begin();
        std::advance(it, index);
        V.push_back(*it);
        L.erase(it);

        saveVectorToFile(V, filename);

        std::cout << "Updated vector V:" << std::endl;
        for (const auto& elem : V) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
