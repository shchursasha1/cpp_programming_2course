#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
using namespace std;

int countWordsWithCharacter(const string& sentence, char target) {
    stringstream ss(sentence);
    string word;
    int count = 0;

    while (ss >> word) {
        if (word.find(target) != string::npos) {
            count++;
        }
    }
    return count;
}

// task 13.15
void task15() {
    string sentence;
    char target;

    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Enter a character to search for: ";
    cin >> target;

    int result = countWordsWithCharacter(sentence, target);
    cout << "Number of words containing the character '" << target << "': " << result << endl;
}

char findMostFrequentVowel(const string& text) {
    unordered_map<char, int> vowelCount;
    string vowels = "aeiou";
    char mostFrequentVowel = '\0';
    int maxCount = 0;

    for (char c : text) {
        char lowerC = tolower(c);

        if (vowels.find(lowerC) != string::npos) {
            vowelCount[lowerC]++;
            if (vowelCount[lowerC] > maxCount) {
                maxCount = vowelCount[lowerC];
                mostFrequentVowel = lowerC;
            }
        }
    }

    return mostFrequentVowel;
}

// task 13.25
void task25() {
    string text;

    cout << "Enter the text: ";
    getline(cin, text);

    char result = findMostFrequentVowel(text);

    if (result != '\0') {
        cout << "The most frequent vowel is: " << result << endl;
    } else {
        cout << "No vowels found in the text." << endl;
    }
}

int main() {
    task25();
}
