#include<iostream>
using namespace std;
#define n 10
class queue{
	public:
	int queue[n];
	int front=-1;
	int rear=-1;
	
	void enqueue(){
		int a;
		if(front==(rear+1)%n){
			cout<<"overflow";
		}
		else{
		if(rear==front&&front==-1){
	    	front=0;
			rear=0;
			cout<<"\nenter the element to add";
			cin>>a;
			queue[rear]=a;
		}
	
		else{
			rear=(rear+1)%n;
			cout<<"\nenter the element to add";
			cin>>a;
			queue[rear]=a;	
		}
	} }
		void dequeue(){
			if(rear==front&&front==-1){
			cout<<"\nunderflow";
			}
			
		else{
		if(front==rear){
			rear = -1;
			front=rear;
		}
			else{
				int item = queue[front];
					front=(front+1)%n;
				cout<<"\nelement deleted"<<item<<" ";
				
				
			}}
		}
	void isempty(){
			if(rear==front&&front==-1){
			cout<<"\nunderflow";
			}
	
	else{
		cout<<"not empty";
	} }
	
	void isfull(){
		if(front==(rear+1)%n){
			cout<<"overflow";
		}
		else{
			cout<<"not full";
		}
			}
	
	void display(){
		if(rear==front&&front==-1){
			cout<<"\nno element";
			}
	
		for(int i=front;i<=rear;i=(i+1)%n){
			cout<<queue[i]<<" ";
		}
	}
	
	void peek(){
		if(rear==front&&front==-1){
			cout<<"\nunderflow";
			}
			
			else{
				cout<<queue[rear]<<" ";
			}
	}
};

int main(){
	queue q; 
	int choice;
do{
	
	 
	cout<<"----menu----";
	cout<<"1.enqueue()";
	cout<<"2.dequeue()";
	cout<<"3.isempty()";
	cout<<"4.isfull()";
	cout<<"5.display()";
	cout<<"6.peek()";
	cout<<"7.exit\n";
	cin>>choice;
	
	switch(choice){
		case 1: q.enqueue();
		break;
		case 2: q.dequeue();
		break;
		case 3: q.isempty();
		break;
		case 4: q.isfull();
		break;
		case 5: q.display();
		break;
		case 6: q.peek();
		break;
		case 7: cout<<"exit";
		
	}
	}
	while(choice!=7);
return 0;	
}
