#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char x) { arr[++top] = x; }
    char pop() { return (top == -1) ? '\0' : arr[top--]; }
    char peek() { return (top == -1) ? '\0' : arr[top]; }
    bool isEmpty() { return top == -1; }
};

int main() {
    char expr[MAX];
    cout << "Enter the expression: ";
    cin >> expr;  

    Stack s;
    int i = 0;
    bool balanced = true;

     
    while (expr[i] != '\0') {
        char ch = expr[i];

         
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
         
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {  
                balanced = false;
                break;
            }

            char topChar = s.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                balanced = false;  
                break;
            }
        }
        i++;  
    }
 
    if (!s.isEmpty()) balanced = false;

    if (balanced)
        cout << "Expression is balanced" << endl;
    else
        cout << "Expression is not balanced" << endl;

    return 0;
}
