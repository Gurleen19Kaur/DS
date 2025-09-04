#include <iostream>
using namespace std;

#define N 100

class Queue {
    int queue[N];   // renamed from arr[] to queue[]
    int front, rear, size;
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int x) {
        if (size == N) {
            cout << "Overflow!\n";
            return;
        }
        rear = (rear + 1) % N;
        queue[rear] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Underflow!\n";
            return -1;
        }
        int val = queue[front];
        front = (front + 1) % N;
        size--;
        return val;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        cout << "Queue: ";
        for (int cnt = 0; cnt < size; cnt++) {
            cout << queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << "\n";
    }

    //Interleave function
    void interleave() {
        if (size % 2 != 0) {
            cout << "Queue has odd number of elements, cannot interleave!\n";
            return;
        }

        int half = size / 2;
        int firstHalf[half], secondHalf[half];

        for (int i = 0; i < half; i++){
		firstHalf[i] = dequeue();
		}

        for (int i = 0; i <half; i++){
		secondHalf[i] = dequeue();}

        for (int i = 0; i < half; i++) {
            enqueue(firstHalf[i]);
            enqueue(secondHalf[i]);
        }
    }
};

int main() {
    Queue q;
    int n, x;

    cout << "Enter even number of elements in queue: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "\nOriginal ";
    q.display();

    q.interleave();

    cout << "Interleaved ";
    q.display();

    return 0;
}
