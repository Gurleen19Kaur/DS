 #include <iostream>
using namespace std;

class Stack {
    char stack[50];
    int top=-1;
public:
    
    
    void push(char x) {
        if(top == 49) {
            cout << "Overflow!!\n";
        } else {
            stack[++top] = x;
        }
    }
    
    char pop() {
        if(top == -1) {
            cout << "Underflow!!\n";
            return '\0';
        } else {
            return stack[top--];
        }
    }
    
    char peek() {
        if(top == -1) return '\0';
        return stack[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

// Function to give priority to operators
int priority(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main() {
    Stack s;
    char infix[50], postfix[50];
    int k = 0;
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    for(int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
      
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
            postfix[k++] = ch;
        }
       
        else if(ch == '(') {
            s.push(ch);
        }
        
        else if(ch == ')') {
        	
            while(!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            if(!s.isEmpty()) s.pop();  
        }
         
        else {
            while(!s.isEmpty() && priority(s.peek()) >= priority(ch)) {
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
    }
    
    
    while(!s.isEmpty()) {
        postfix[k++] = s.pop();
    }
    
    postfix[k] = '\0';
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
