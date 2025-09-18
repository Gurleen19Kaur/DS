#include <iostream>
using namespace std;
#define N 100

class Queue {
    int arr[N];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }

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

    bool isEmpty() { return front > rear; }

    int getSize() { return rear - front + 1; }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    // find index of minimum element among first (limit+1) elements
    int minIndex(int limit) {
        int sz = getSize();
        int min_idx = -1;
        int min_val;
        bool firstTaken = false;

        for (int i = 0; i < sz; i++) {
            int curr = dequeue();
            if (!firstTaken) {           // first element becomes initial min
                min_val = curr;
                min_idx = i;
                firstTaken = true;
            }
            if (i <= limit && curr < min_val) {
                min_val = curr;
                min_idx = i;
            }
            enqueue(curr);
        }
        return min_idx;
    }

    void insertMinToRear(int min_idx) {
        if (min_idx < 0) return;
        int sz = getSize();
        int min_val = 0;
        for (int i = 0; i < sz; i++) {
            int curr = dequeue();
            if (i == min_idx) {
                min_val = curr;  // skip once
            } else {
                enqueue(curr);
            }
        }
        enqueue(min_val);
    }

    void sortQueue() {
        int n = getSize();
        for (int i = 1; i <= n; i++) {
            int limit = n - i;
            int min_idx = minIndex(limit);
            insertMinToRear(min_idx);
        }
    }
};

int main() {
    Queue q;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x; q.enqueue(x);
    }

    cout << "Original queue: ";
    q.display();

    q.sortQueue();

    cout << "Sorted queue: ";
    q.display();

    return 0;
}


