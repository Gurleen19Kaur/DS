#include <iostream>
using namespace std;

class Stack {
    int arr[100];  
    int top;       
public:
    Stack() { top = -1; }  

    void push(int x) {
        top++;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) return -1;  
        int val = arr[top];
        top--;
        return val;
    }

    int peek() {
        if (top == -1) return -1; 
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int A[100], sortedA[100], N;

    cout << "Enter size of array: ";
    cin >> N;

    cout << "Enter elements of array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sortedA[i] = A[i]; 
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1-i; j++) {
            if (sortedA[j] > sortedA[j+1]) {
                int temp = sortedA[j];
                sortedA[j] = sortedA[j+1];
                sortedA[j+1] = temp;
            }
        }
    }

    Stack S;
    int in
