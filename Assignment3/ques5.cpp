#include <iostream>
#include <cmath>
using namespace std;
#define n 20

class stack {
    int stack[n];
    int top=-1;
    
    public:
    	 void push(int a){
        if(top == n-1) {
            cout << "Overflow!!\n";
        } else {
        	top++;
            stack[top] = a ;
        }
    }
    
    int pop(){
    	if(top == -1) {
            cout << "Underflow!!\n";
            return '\0';
        } else {
            int item=stack[top];
            top--;
            return item;
        }
	}
    
    
    	 	
		 };
		 
		 int main(){
		 	stack s;
		 	char postfix[50];
		 	
		 	cout<<"enetr the postfix expression";
		 	cin >> postfix;
		 	int z=0;
		 	while(postfix[z]!='\0'){
		 		z++;
			 }
		 	
		 	for(int i =0;i<z;i++){
		 		int ch = postfix[i];
		 		 if(ch >= '0' && ch <= '9'){
		 			  s.push(ch - '0');
				 }
				 
				 else{
				 	int b=s.pop();
				 	int a=s.pop();
				 	
				 	  if (ch == '+') {
					   s.push(a + b);}
            else if (ch == '-') {
			s.push(a - b);}
            else if (ch == '*'){
			s.push(a * b);}
            else if (ch == '/') {
			s.push(a / b);}
            else if (ch == '^'){
			 s.push(pow(a, b));}
			 }
		}
		
			  cout << "Result: " << s.pop() << endl;
			 return 0;
			
		 }
