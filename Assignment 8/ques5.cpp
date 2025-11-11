#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortIncreasing(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapSortDecreasing(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\nChoose sorting order:\n1. Increasing Order\n2. Decreasing Order\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        heapSortIncreasing(arr, n);
        cout << "\nSorted array in Increasing Order:\n";
    } else if (choice == 2) {
        heapSortDecreasing(arr, n);
        cout << "\nSorted array in Decreasing Order:\n";
    } else {
        cout << "Invalid choice!\n";
        delete[] arr;
        return 0;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
