#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace MyNamespace {
    template <typename T>
    class Stack {
    private:
        vector<T> elements;

    public:
        void push(const T& value) {
            elements.push_back(value);
        }

        void pop() {
            if (elements.empty()) {
                throw out_of_range("stack is empty");
            }
            elements.pop_back();
        }

        T& top() {
            if (elements.empty()) {
                throw out_of_range("stack is empty");
            }
            return elements.back();
        }

        const T& top() const {
            if (elements.empty()) {
                throw out_of_range("stack is empty");
            }
            return elements.back();
        }

        bool empty() const {
            return elements.empty();
        }

        size_t size() const {
            return elements.size();
        }
    };
    template <typename StackType>
    int readArray(StackType& stack, int*& result) {
        int input;
        cout << "Enter integers (end with 0): ";
        while (cin >> input && input != 0) {
            stack.push(input);
        }

        int count = stack.size();
        result = new int[count];
        for (int i = count - 1; i >= 0; i--) {
            result[i] = stack.top();
            stack.pop();
        }
        return count;
    }

}

int main() {
    using namespace MyNamespace;

    Stack<int> myStack;
    int* resultArray = nullptr;
    int count = readArray(myStack, resultArray);

    cout << "Elements in the array: ";
    for (int i = 0; i < count; i++) {
        cout << resultArray[i] << " ";
    }
    cout << endl;
    delete[] resultArray;
    stack<int> stdStack;
    int* resultArrayStd = nullptr;
    count = readArray(stdStack, resultArrayStd);

    cout << "Elements in the array (stack): ";
    for (int i = 0; i < count; i++) {
        cout << resultArrayStd[i] << " ";
    }
    cout << endl;
    delete[] resultArrayStd;

    return 0;
}