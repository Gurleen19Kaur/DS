#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int min;  // current minimum
public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == -1) {
            top++;
            arr[top] = x;
            min = x;
        } else if (x >= min) {
            top++;
            arr[top] = x;
        } else {
            arr[top + 1] = 2*x - min; // store special value
            top++;
            min = x;
        }
        cout << "Pushed: " << x << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        int y = arr[top];
        top--;
        if (y < min) {
            min = 2*min - y; // restore previous minimum
        }
        cout << "Element popped\n";
    }

    int getMin() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return min;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Operations ---\n";
        cout << "1. Push\n2. Pop\n3. Get Min\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Minimum element: " << s.getMin() << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
