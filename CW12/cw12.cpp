#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

void task1() {
    double x, y;

    cin >> x >> y;
    double result = pow(x, y);
    cout << result << ", " << scientific << result << endl;
}

void task2() {
    char string[10];
    unsigned long long  sum = 0UL;
    unsigned a, n = 0;
    unsigned array[1000];

    cout << "Enter: \n";
    size_t sz;

    while (cin.get(string, 10)) {
        cout << string << "," << endl;
        a = stoull(string, &sz);
        array[n] = a;
        n++;
        sum += a;
    }
    cout << sum << endl;
}

void task3() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << string(10 * n + 1, '+') << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << setw(6) << i << "   ";
    }
    cout << "\n";

    cout << string(10 * n + 1, '+') << "\n";

    for (int i = 1; i <= n; ++i) {
        double root = sqrt(i);
        cout << setw(6) << fixed << setprecision(root == static_cast<int>(root) ? 0 : 2) << root << "   ";
    }
    cout << "\n";

    cout << string(10 * n + 1, '+') << "\n";
}

int task4() {
    unsigned n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n must be greater that 0" << endl;
        return 1;
    }

    int* array = new int[n];
    cout << "Enter" << n << "numbers" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    ifstream file1("input.txt");
    if (!file1.is_open()) {
        cout << "File does not exist" << endl;
        delete[] array;
        return 1;
    }

    int* file_array = new int[n];

    for (int i = 0; i < n; i++) {
        if (!(file1 >> file_array[i])) {
            cerr << "Can't read number from file or file has fewer numbers!" << endl;
            delete[] file_array;
            delete[] array;
            file1.close();
            return 1;
        }
    }

    file1.close();

    ofstream file2("file.txt");
    if (!file2.is_open()) {
        cerr << "Can't open file for writing!" << endl;
        delete[] file_array;
        delete[] array;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        double result = pow(array[i], file_array[i]);
        file2 << result << ' ';
    }
    file2.close();

    delete[] file_array;
    delete[] array;
}

int task5() {
    ifstream file("file.txt");

    if (!file.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    long long* numbers = nullptr;
    int size = 0;
    int capacity = 10;

    numbers = new long long[capacity];
    long long number;

    while (file >> number) {
        if (size >= capacity) {
            capacity *= 2;
            long long* new_numbers = new long long[capacity];
            for (int i = 0; i < size; i++) {
                new_numbers[i] = numbers[i];
            }
            delete[] numbers;
            numbers = new_numbers;
        }
        numbers[size++] = number;
    }
    file.close();

    double* new_numbers = new double[size];
    for (int i = 0; i < size; i++) {
        new_numbers[i] = sqrt(numbers[i]);
    }

    for (int i = size - 1; i >= 0; i--) {
        cout << fixed << setprecision(3) << new_numbers[i] << endl;
    }

    delete[] numbers;
    delete[] new_numbers;

    return 0;
}


int main() {
    task5();
}
