#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

struct ClientData {
    int clientCode;
    int year;
    int month;
    int hours;

    ClientData(int code, int y, int m, int h)
        : clientCode(code), year(y), month(m), hours(h) {}
};

int main() {
    std::string filename = "clients.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::vector<ClientData> clients;
    int minHours = std::numeric_limits<int>::max();

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int code, year, month, hours;
        if (iss >> code >> year >> month >> hours) {
            clients.emplace_back(code, year, month, hours);
            if (hours < minHours) {
                minHours = hours;
            }
        } else {
            std::cerr << "Error: Invalid line format: " << line << std::endl;
        }
    }
    inputFile.close();

    std::vector<ClientData> minClients;
    for (const auto& client : clients) {
        if (client.hours == minHours) {
            minClients.push_back(client);
        }
    }

    std::cout << "Clients with minimum hours (" << minHours << "):" << std::endl;
    for (const auto& client : minClients) {
        std::cout << "Client Code: " << client.clientCode
                  << ", Year: " << client.year
                  << ", Month: " << client.month
                  << ", Hours: " << client.hours
                  << std::endl;
    }

    return 0;
}
