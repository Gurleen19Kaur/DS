 #include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(int x) { arr[++top] = x; }
    int pop() { return (top == -1) ? -1 : arr[top--]; }
    int peek() { return (top == -1) ? -1 : arr[top]; }
    bool isEmpty() { return top == -1; }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n], nge[n];   
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> A[i];

    Stack s;

    
    for(int i = n - 1; i >= 0; i--) {
        while(!s.isEmpty() && s.peek() <= A[i])
            s.pop();

        if(s.isEmpty()) nge[i] = -1;   
        else nge[i] = s.peek();      

        s.push(A[i]);  
    }

    // Print Next Greater Elements in original order
    cout << "Next Greater Elements: ";
    for(int i = 0; i < n; i++)
        cout << nge[i] << " ";
    cout << endl;

    return 0;
}
