#include<iostream>
using namespace std;
#define n 5
 
class stack{
	
	public:
	int stack[n];
	int top=-1;
	
void push(){
		int a;
	if(top==n-1){
		cout<<"overflow!!";
	}
	else{
		cout<<"enter a num to push";
		cin>>a;
		top++;
		stack[top]=a;
	}
}

void pop(){
	if(top==-1){
		cout<<"underflow";
	}
	else{
		int item = stack[top];
		cout<<item<<" ";
		top--;
	}
}	
	
    void isempty() {
    if (top == -1) 
        cout << "Stack is empty\n";
    else 
        cout << "Stack is not empty\n";
}
    void isfull() {
    if (top == n - 1) 
        cout << "Stack is full\n";
    else 
        cout << "Stack is not full\n";
}
	
	void peek(){
		if(top==-1){
			cout<<"no element";
		}
		else{
		cout<<stack[top]<<" ";
	}
	}
	
	void display(){
		for(int i=0;i<=top;i++){
			cout<<stack[i]<<" ";
		}
	}
	
};


int main(){
	
	stack s; 
	int choice;
do{
	
	 
	cout<<"----menu----";
	cout<<"1.push()";
	cout<<"2.pop()";
	cout<<"3.isempty()";
	cout<<"4.isfull()";
	cout<<"5.display()";
	cout<<"6.peek()";
	cout<<"7.exit";
	cin>>choice;
	
	switch(choice){
		case 1: s.push();
		break;
		case 2: s.pop();
		break;
		case 3: s.isempty();
		break;
		case 4: s.isfull();
		break;
		case 5 :s.display();
		break;
		case 6: s.peek();
		break;
		case 7: cout<<"exit";
		
	}
	}
	while(choice!=7);
return 0;	
}
