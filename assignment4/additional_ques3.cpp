#include <iostream>
using namespace std;
#define N 100

class Queue {
public:
    int arr[N];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == N - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        return arr[front++];
    }

    int getFront() {
        if (front > rear) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

class Stack {
public:
    int arr[N];
    int top;

    Stack() { top = -1; }

    void push(int x) {
        if (top == N - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool checkSorted(Queue &input, int n) {
    Queue output;
    Stack st;
    int expected = 1;

    while (!input.isEmpty()) {
        int curr = input.dequeue();

        if (curr == expected) {
            output.enqueue(curr);
            expected++;
        } else {
            while (!st.isEmpty() && st.peek() == expected) {
                output.enqueue(st.pop());
                expected++;
            }
            if (!st.isEmpty() && st.peek() < curr)
                return false; 
            st.push(curr);
        }
    }

    while (!st.isEmpty()) {
        if (st.peek() != expected) return false;
        output.enqueue(st.pop());
        expected++;
    }

    return expected == n + 1;
}

int main() {
    Queue q;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    if (checkSorted(q, n))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

