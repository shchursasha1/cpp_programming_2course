#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

double norm(const vector<double>& vec) {
    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        double val = vec[i];
        sum += pow(val, 2);
    }
    return sqrt(sum);
}

int main() {
    int n, d;

    cout << "Enter number of vectors (n): ";
    cin >> n;

    cout << "Enter dimension of vectors (d): ";
    cin >> d;
    vector<vector<double>> vectors(n, vector<double>(d));

    for (int i = 0; i < n; ++i) {
        cout << "Enter vector " << i + 1 << " (size " << d << "): ";
        for (int j = 0; j < d; ++j) {
            cin >> vectors[i][j];
        }
    }

    double sum_of_norms = 0;
    for (const auto& vec : vectors) {
        sum_of_norms += norm(vec);
    }
    cout << "Norms sum: " << sum_of_norms << endl;
}
