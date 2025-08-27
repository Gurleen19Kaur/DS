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
    cout<<"emter number of elements";
    cin >> n;
    int A[n];
    cout<<"enter array elemnts";
    for(int i=0;i<n;i++) cin >> A[i];

    Stack s;

    for(int i=0;i<n;i++){
         
        while(!s.isEmpty() && s.peek() >= A[i])
            s.pop();

        if(s.isEmpty()) cout << -1 << " ";  
        else cout << s.peek() << " ";     

        s.push(A[i]);  
    }
    cout << endl;
    return 0;
}
