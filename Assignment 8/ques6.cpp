#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.size() == 0;
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(60);

    cout << "Heap: ";
    pq.display();

    cout << "Max: " << pq.top() << endl;

    pq.pop();
    cout << "After pop: ";
    pq.display();

    return 0;
}
