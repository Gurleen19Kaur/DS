#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryHeap {
    vector<T> a;
    bool isMin;

    bool compare(const T &x, const T &y) const {
        return isMin ? (x < y) : (x > y);
    }

    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (compare(a[idx], a[parent])) {
                swap(a[idx], a[parent]);
                idx = parent;
            } else break;
        }
    }

    void siftDown(int idx) {
        int n = a.size();
        while (true) {
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            int best = idx;
            if (l < n && compare(a[l], a[best])) best = l;
            if (r < n && compare(a[r], a[best])) best = r;
            if (best == idx) break;
            swap(a[idx], a[best]);
            idx = best;
        }
    }

public:
    BinaryHeap(bool minHeap = false) : isMin(minHeap) {}

    void push(const T &val) {
        a.push_back(val);
        siftUp(a.size() - 1);
    }

    void pop() {
        if (a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) siftDown(0);
    }

    const T& top() const {
        return a[0];
    }

    bool empty() const { return a.empty(); }
    int size() const { return a.size(); }

    void buildFrom(const vector<T> &vals) {
        a = vals;
        for (int i = a.size() / 2 - 1; i >= 0; i--) siftDown(i);
    }
};

int main() {
    BinaryHeap<int> maxpq(false);
    maxpq.push(20);
    maxpq.push(5);
    maxpq.push(15);
    maxpq.push(22);
    maxpq.push(3);

    cout << "Max-heap order pops: ";
    while (!maxpq.empty()) {
        cout << maxpq.top() << " ";
        maxpq.pop();
    }
    cout << "\n";

    BinaryHeap<int> minpq(true);
    minpq.push(20);
    minpq.push(5);
    minpq.push(15);
    minpq.push(22);
    minpq.push(3);

    cout << "Min-heap order pops: ";
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << "\n";

    return 0;
}
