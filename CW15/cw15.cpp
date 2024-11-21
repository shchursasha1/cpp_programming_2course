#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Функція, яка повертає новий рядок (for task 1)
string extractSubstringNew(const string& input) {
    size_t colonPos = input.find(':');
    if (colonPos == string::npos) {
        return input;
    }

    size_t commaPos = input.find(',', colonPos + 1);
    if (commaPos == string::npos) {
        return input.substr(colonPos + 1);
    }

    return input.substr(colonPos + 1, commaPos - colonPos - 1);
}

// Функція, яка змінює рядок (for task 1)
void extractSubstringInPlace(string& input) {
    size_t colonPos = input.find(':');
    if (colonPos == string::npos) {
        // Двокрапки немає, рядок не змінюється
        return;
    }

    size_t commaPos = input.find(',', colonPos + 1);
    if (commaPos == string::npos) {
        input = input.substr(colonPos + 1);
        return;
    }

    input = input.substr(colonPos + 1, commaPos - colonPos - 1);
}

void task1() {
    string input1 = "Example:substring,rest of the line";
    string input2 = "No colon here";
    string input3 = "Colon only: rest";

    cout << "Original: " << input1 << endl;
    cout << "Result (new string): " << extractSubstringNew(input1) << endl;

    cout << "\nOriginal: " << input1 << endl;
    extractSubstringInPlace(input1);
    cout << "Result (in place): " << input1 << endl;
}

// for task 2
string processStringNew(const string& input) {
    size_t firstDot = input.find('.');
    size_t lastDot = input.rfind('.');

    if (firstDot == string::npos) {
        string result = input;
        result.erase(0, result.find_first_not_of(' '));
        return result;
    }

    if (firstDot == lastDot) {
        return input.substr(firstDot + 1);
    }

    string result = input;
    result.erase(firstDot, lastDot - firstDot + 1);
    return result;
}

void processStringInPlace(string& input) {
    size_t firstDot = input.find('.');
    size_t lastDot = input.rfind('.');

    if (firstDot == string::npos) {
        input.erase(0, input.find_first_not_of(' '));
        return;
    }

    if (firstDot == lastDot) {
        input = input.substr(firstDot + 1);
        return;
    }

    input.erase(firstDot, lastDot - firstDot + 1);
}

void task2() {
    string input1 = " This is a test. Remove this part. End.";
    string input2 = "No dots here, only spaces.";
    string input3 = "Single dot. And text after.";

    cout << "Original: " << input1 << endl;
    cout << "Result (new string): " << processStringNew(input1) << endl;

    cout << "\nOriginal: " << input1 << endl;
    processStringInPlace(input1);
    cout << "Result (in place): " << input1 << endl;
}

// for task 3
string processWordsNew(const string& input) {
    stringstream ss(input);
    string word;
    string result;
    bool firstWord = true;

    while (ss >> word) {
        if (!word.empty()) {
            word.pop_back();
        }

        if (!firstWord) {
            result += " ";
        }
        result += word;
        firstWord = false;
    }

    size_t endPos = input.find_last_not_of(' ');
    if (endPos != string::npos && endPos + 1 < input.length()) {
        result += string(input.length() - endPos - 1, ' ');
    }

    return result;
}

void processWordsInPlace(string& input) {
    stringstream ss(input);
    string word;
    string result;
    bool firstWord = true;

    while (ss >> word) {
        if (!word.empty()) {
            word.pop_back();
        }

        if (!firstWord) {
            result += " ";
        }
        result += word;
        firstWord = false;
    }

    size_t endPos = input.find_last_not_of(' ');
    if (endPos != string::npos && endPos + 1 < input.length()) {
        result += string(input.length() - endPos - 1, ' ');
    }

    input = result;
}

void task3() {
    string input1 = "Hello world  test string ";
    string input2 = input1;

    cout << "Original: \"" << input1 << "\"" << endl;
    string resultNew = processWordsNew(input1);
    cout << "Result (new string): \"" << resultNew << "\"" << endl;

    processWordsInPlace(input2);
    cout << "Result (in place): \"" << input2 << "\"" << endl;
}

// for task 4
vector<double> extractNumbers(const string &input, char separator, int n) {
    vector<double> numbers;
    stringstream ss(input);
    string token;
    int count = 0;

    while (getline(ss, token, separator) && count < n) {
        try {
            double num = stod(token); // Перетворення токену на число
            numbers.push_back(num);
            count++;
        } catch (invalid_argument &) {
            continue;
        }
    }

    return numbers;
}

void task4() {
    string input;
    char separator;
    int n;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Enter the separator: ";
    cin >> separator;
    cout << "Enter the number of values to extract (n): ";
    cin >> n;

    vector<double> result = extractNumbers(input, separator, n);

    cout << "Extracted numbers: ";
    for (double num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// for task 5
vector<string> splitWords(const string &input, char separator, int n) {
    vector<string> words;
    stringstream ss(input);
    string token;
    int count = 0;

    while (getline(ss, token, separator) && count < n) {
        words.push_back(token);
        count++;
    }

    return words;
}

void task5() {
    string input;
    char separator;
    int n;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Enter the separator: ";
    cin >> separator;
    cout << "Enter the number of words to extract (n): ";
    cin >> n;

    vector<string> result = splitWords(input, separator, n);

    cout << "Extracted words: ";
    for (const string &word : result) {
        cout << word << " ";
    }
    cout << endl;
}

// for task 6
string findFirstShortestWord(const string& sentence) {
    stringstream ss(sentence);
    string word, shortestWord;
    size_t minLength = SIZE_MAX;

    while (ss >> word) {
        if (word.length() < minLength) {
            shortestWord = word;
            minLength = word.length();
        }
    }
    return shortestWord;
}

string findLastShortestWord(const string& sentence) {
    stringstream ss(sentence);
    string word, shortestWord;
    size_t minLength = SIZE_MAX;

    while (ss >> word) {
        if (word.length() < minLength) {
            shortestWord = word;
            minLength = word.length();
        } else if (word.length() == minLength) {
            shortestWord = word;
        }
    }
    return shortestWord;
}

vector<string> findAllShortestWords(const string& sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> shortestWords;
    size_t minLength = SIZE_MAX;

    while (ss >> word) {
        if (word.length() < minLength) {
            minLength = word.length();
        }
    }

    ss.clear();
    ss.str(sentence);
    while (ss >> word) {
        if (word.length() == minLength) {
            shortestWords.push_back(word);
        }
    }

    return shortestWords;
}

void task6() {
    string sentence = "This is an example of a test sentence";

    string firstShortest = findFirstShortestWord(sentence);
    cout << "First shortest word: " << firstShortest << endl;

    string lastShortest = findLastShortestWord(sentence);
    cout << "Last shortest word: " << lastShortest << endl;

    vector<string> allShortest = findAllShortestWords(sentence);
    cout << "All shortest words: ";
    for (const string& word : allShortest) {
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    task6();
}