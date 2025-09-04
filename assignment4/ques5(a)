#include <iostream>
using namespace std;
#define N 100

class Queue {
public:
    int arr[N];
    int front = 0, rear = -1, size = 0;

    void enqueue(int x) {
        if (size == N) return;
        rear = (rear + 1) % N;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) return -1;
        int val = arr[front];
        front = (front + 1) % N;
        size--;
        return val;
    }

    int getFront() {
        if (size == 0) return -1;
        return arr[front];
    }

    int getSize() { return size; }

    void display() {
        if (size == 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = 0, idx = front; i < size; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % N;
        }
        cout << "\n";
    }

    bool isEmpty() { return size == 0; }
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);                // Step 1: enqueue new element in q2
        while (!q1.isEmpty())         // Step 2: move all elements from q1 to q2
            q2.enqueue(q1.dequeue());
        swap(q1, q2);                 // Step 3: swap q1 and q2
    }

    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) return -1;
        return q1.getFront();
    }

    void display() {
        q1.display();
    }
};

int main() {
    Stack s;
    int choice, x;

    do {
        cout << "\n----Stack Menu----\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> x;
                s.push(x);
                break;
            case 2:
                x = s.pop();
                if (x != -1) cout << "Popped: " << x << "\n";
                break;
            case 3:
                x = s.top();
                if (x != -1) cout << "Top element: " << x << "\n";
                else cout << "Stack is empty\n";
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);

    return 0;
}
