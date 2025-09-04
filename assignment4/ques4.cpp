#include <iostream>
using namespace std;
#define N 100

class Queue {
public:
    char queue[N];
    int front = 0, rear = -1, size = 0;

    void enqueue(char x) {
        if (size == N) return;
        rear = (rear + 1) % N;
        queue[rear] = x;
        size++;
    }

    char dequeue() {
        if (size == 0) return '\0';
        char val = queue[front];
        front = (front + 1) % N;
        size--;
        return val;
    }

    char getFront() {
        if (size == 0) return '\0';
        return queue[front];
    }

    bool isEmpty() { return size == 0; }

    bool contains(char x) {
        int i = front;
        for (int cnt = 0; cnt < size; cnt++) {
            if (queue[i] == x) return true;
            i = (i + 1) % N;
        }
        return false;
    }

    void remove(char x) {
        int count = 0;
        int i = front;
        while (count < size) {
            if (queue[i] == x) {
                // shift elements left
                for (int j = i; j != rear; j = (j + 1) % N)
                    queue[j] = queue[(j + 1) % N];
                rear = (rear - 1 + N) % N;
                size--;
                break;
            }
            i = (i + 1) % N;
            count++;
        }
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    Queue temp;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == ' ') continue;

        if (!temp.contains(ch))
            temp.enqueue(ch);
        else
            temp.remove(ch);

        if (!temp.isEmpty())
            cout << temp.getFront() << " ";
        else
            cout << "-1 ";
    }

    cout << "\n";
    return 0;
}
