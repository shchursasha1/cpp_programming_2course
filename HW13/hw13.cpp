#include <iostream>
#include <fstream>
#include <string>

// task 14.22
int main() {
    std::string fileF = "F.txt";
    std::string fileH = "H.txt";
    std::string fileG = "G.txt";

    int N;
    std::cout << "Enter the number of lines in file F: ";
    std::cin >> N;
    std::cin.ignore();

    std::ofstream foutF(fileF);
    if (!foutF) {
        std::cerr << "Error creating file F.\n";
        return 1;
    }

    std::cout << "Enter " << N << " lines for file F:\n";
    for (int i = 0; i < N; i++) {
        std::string line;
        std::getline(std::cin, line);
        foutF << line << "\n";
    }
    foutF.close();

    std::ifstream finF(fileF);
    if (!finF) {
        std::cerr << "Error opening file F for reading.\n";
        return 1;
    }

    std::ofstream foutH(fileH);
    std::ofstream foutG(fileG);
    if (!foutH || !foutG) {
        std::cerr << "Error creating files H or G.\n";
        return 1;
    }

    std::string line;
    while (std::getline(finF, line)) {
        if (line.length() % 2 == 0) {
            foutG << line << "\n";
        } else {
            foutH << line << "\n";
        }
    }

    finF.close();
    foutH.close();
    foutG.close();

    return 0;
}
