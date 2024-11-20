#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

int task1() {
    char filename[] = "cw14_1.txt";
    fstream f(filename);

    if (!f) {
        cerr << "Can't open file " << filename << endl;
        return -1;
    }

    char c;
    int num = 0;
    int num2 = 0;
    int sum = 0;
    int prev_sign = 0;

    while (f >> c) {
        if (isdigit(c)) {
            int d = c - '0;
            num = num * 10 + d;
        }
        else if (c == '-') {
            num2 = num;
            num = 0;

            if (prev_sign == 1 || prev_sign == 0) {
            sum += num2;
            }

            else if (prev_sign == 2) {
                sum -= num2;
            }
            prev_sign = 2;
            cout << sum << "i";
        }
        else if (c == '+') {
            num2 = num;
            num = 0;

            if (prev_sign == 1 || prev_sign == 0) {
                sum += num2;

            }
            else if (prev_sign == 2) {
                sum -= num2;
            }
            prev_sign = 1;
            cout << sum << "i";
        }
        else if (c == '=') {
            num2 = num;
            if (prev_sign == 1) {
                sum += num2;
            }
            else if (prev_sign == 2) {
                sum -= num2;
            }
            cout << "sum" << sum << "\n";
        }
        else {
            cout << "Not required format: " << c << "- incorrect symbol \n";
        }
    }

}

int task2() {
    char fname[20] = "deutsch.txt";
    ifstream f(fname);
    string Articles[] = {"der", "die", "das"};
    string buff;
    bool is_article = false;
    ofstream f2("tmp.txt");

    while(f >> buff) {
        if (is_article) {
            buff[0] = toupper(buff[0]);
        }

        clog << buff << " ";
        f2 << buff << " ";
        is_article = false;

        for (int i = 0; i < 3; i++) {
            if (buff == Articles[i]) {
                is_article = true;
                break;
            }
        }
    }
    f.close();
    f2.close();
    rename("tmp.txt", fname);
}

string reverseString(const string& str) {
    string reversed_str;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed_str += str[i];
    }
    return reversed_str;
}

int task3() {
    ifstream file1("file.txt");
    if (!file1.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string str;
    string* words = new string[100];
    int size = 0;
    while(file1 >> str) {

        if (size >= 100) {
            cerr << "Exceeded maximum number of words" << endl;
            break;
        }
        words[size++] = str;
    }
    file1.close();

    ofstream file2("file.txt");
    if (!file2.is_open()) {
        cerr << "Can't open file" << endl;
        delete[] words;
        return 1;
    }

    for(int i = 0; i < size; i++) {
        file2 << reverseString(words[i]) << ' ';
    }

    file2.close();
    delete[] words;

    return 0;
}

bool checkTags(ifstream f1, string openTD = "<td>", string closeTD = "</td>") {
    int opentag = 0;
    int closedtag = 0;
    string buf;

    while (!f1.eof()) {
        if (f1 >> buf) {
            if (buf == openTD) {
                opentag ++;
            }
            else if (buf == closeTD) {
                closedtag ++;
            }
            if (closedtag > opentag) {
                return false;
            }
            else {
                break;
            }
        }
        return closedtag == opentag;
    }
}

void task4() {
    const char* fileName = "file.txt";
    ifstream f1(fileName);

    if (f1.bad()) {
        cerr << "Error opening file " << fileName << endl;
    }

    cout << "Check" << boolalpha << checkTags(f1);
    f1.close();
}

void createStudentFile(const char* fname) {
    ofstream f1(fname);
    unsigned N;

    cout << "Enter number of students: ";
    cin >> N;

    string surname;
    int course;
    string group;
    string marks;

    for (int i = 0; i < N; i++) {
        cin >> surname >> course >> group >> marks;
        f1 << surname << ' ' <<  course << ' ' << group << ' ' << marks << '\n';
    }
    f1.close();
}

double averageMark(string marks) {
    double sum = 0;
    int counter = 0, tmp;
    char coma = '\'';
    stringstream str(marks);

    while (str >> tmp) {
        sum += tmp;
        counter++;
        str >> coma;
    }
    return sum / counter;
}

string findStudent(const char* fname) {
    double min_mark = 12;
    string student_with_lowest_avg_mark;
    ifstream f1(fname);

    while(!f1.eof()) {
        string surname, course, group, marks;
        f1 >> surname >> course >> group >> marks;
        double average_mark = averageMark(marks);

        if (average_mark < min_mark) {
            min_mark = average_mark;
            student_with_lowest_avg_mark = surname;
        }
    }
    return student_with_lowest_avg_mark;

    f1.close();
}

void task5() {
    createStudentFile("students.txt");
    cout << findStudent("students.txt") << endl;
}